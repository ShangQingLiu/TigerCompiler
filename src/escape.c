#include "escape.h"
#include "symbol.h"
#include "utils.h"

typedef struct escape_entry_s *escape_entry_t;
struct escape_entry_s
{
    int depth;
    bool *escape;
};

static escape_entry_t escape_entry(int depth, bool *pEscape)
{
    assert(pEscape);
    escape_entry_t p = checked_malloc(sizeof(*p));
    p->depth = depth;
    p->escape = pEscape;
    //*pEscape = false;
    return p;
}

static int _depth;
static table_t _env;

static void traverse_decl(dec_t decl);
static void traverse_expr(exp_t expr);
static void traverse_var(var_t var);

static void traverse_decl(dec_t decl)
{
    switch (decl->kind)
    {
        case A_functionDec: {
            fundecList_t p = decl->u.function;
            for (; p; p = p->tail)
            {
                fundec_t func = p->head;
                fieldList_t q;

                _depth++;
                SymbolBeginScope(_env);
                for (q = func->params; q; q = q->tail)
                {
                    field_t field = q->head;
                    SymbolEnter(_env,
                              field->name,
                              escape_entry(_depth, &field->escape));
                }
                traverse_expr(func->body);
                SymbolEndScope(_env);
                _depth--;
            }
            break;
        }

        case A_typeDec:
            break;

        case A_varDec:
            SymbolEnter(_env,
                      decl->u.var.var,
                      escape_entry(_depth, &decl->u.var.escape));
            traverse_expr(decl->u.var.init);
            break;
    }
}

static void traverse_expr(exp_t expr)
{
   // list_t p;

    switch (expr->kind)
    {
        case A_nilExp:
		case A_intExp:
        case A_stringExp:
		case A_breakExp:
            break;

        case A_varExp:
            traverse_var(expr->u.var);
            break;

        case A_callExp:{
			expList_t p;
            for (p = (expr->u.call.args); p; p = p->tail)
                traverse_expr(p->head);
            break;
		}

        case A_opExp:
            traverse_expr(expr->u.op.left);
            traverse_expr(expr->u.op.right);
            break;

        // 记录类型和数组类型的初始化
        case A_recordExp:{
			efieldList_t p;
            for (p = (expr->u.record.fields); p; p = p->tail)
                traverse_expr(p->head->exp);
            break;
		}

        case A_arrayExp:
            traverse_expr(expr->u.array.size);
            traverse_expr(expr->u.array.init);
            break;

        case A_seqExp: {
			expList_t p;
            for (p = (expr->u.seq); p; p = p->tail)
                traverse_expr(p->head);
            break;
		}

        case A_ifExp:
            traverse_expr(expr->u.iff.test);
            traverse_expr(expr->u.iff.then);
            if (expr->u.iff.elsee)
                traverse_expr(expr->u.iff.elsee);
            break;

        case A_whileExp:
            traverse_expr(expr->u.whilee.test);
            traverse_expr(expr->u.whilee.body);
            break;

        case A_forExp:
            traverse_expr(expr->u.forr.lo);
            traverse_expr(expr->u.forr.hi);
            SymbolBeginScope(_env);
            SymbolEnter(_env,
                      expr->u.forr.var,
                      escape_entry(_depth, &expr->u.forr.escape));
            traverse_expr(expr->u.forr.body);
            SymbolEndScope(_env);
            break;

        case A_letExp: {
			decList_t p;
            SymbolBeginScope(_env);
            for (p = expr->u.let.decs; p; p = p->tail)
                traverse_decl(p->head);
            traverse_expr(expr->u.let.body);
            SymbolEndScope(_env);
            break;
		}

        case A_assignExp:
            traverse_var(expr->u.assign.var);
            traverse_expr(expr->u.assign.exp);
            break;
    }
}

static void traverse_var(var_t var)
{
    switch (var->kind)
    {
        case A_simpleVar: {
            escape_entry_t entry = SymbolLookup(_env, var->u.simple);
            if (entry && entry->depth < _depth)
                *(entry->escape) = TRUE;
            break;
        }

        case A_fieldVar:
            traverse_var(var->u.field.var);
            break;

        case A_subscriptVar:
            // 数组类型？
            traverse_var(var->u.subscript.var);
            traverse_expr(var->u.subscript.exp);            
            break;
    }
}

void Esc_findEscape(exp_t expr)
{
    _depth = 0;
    _env = SymbolEmpty();
    traverse_expr(expr);
}
