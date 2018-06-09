# TigerCompiler
2018 Courses Design
Reference book "Modern Compiler Implementation in C".
The structure of whole TigerCompiler. (Order in desigh step)
`‵`
|-ch1
  |--util---常用工具函数集
|-ch2
  |--tiger.l---生成token(词法分析)
  |--errormsg---tigerCompiler错误信息
|-ch3
  |--lex.yy.c---语法分析
|-ch4
  |--table---处理一个对应keys和values的表
  |--symbol---基于Table生成符号表并使用
  |--ast---语法分析树定义与生成
|-ch5(语义分析)
  |--type---定义各种tiger数据类型的结构
  |--semant---类型检查
|-ch6
  |--semant---为局部变量分配储存单元
  |--escape---处理逃逸变量
  |--frame---栈帧的处理
  |--traslate---生成IR
|-ch7
  |--tree---中间表示树的结构
  |--translate---生成IR
|-ch8
  |--canonical---中间表示树标准化
|-ch9
  |--x86codegen---IR转x86汇编(没有寄存器分配)
|-ch10
  |--graph---图的抽象数据类型
  |--flowgraph---控制流图
  |--liveness---活跃分析
|-ch11
  |--color---生成冲突使用George合并然后计算溢出，如果溢出就将溢出节点聚集，最后要重新进行一次新的着色
