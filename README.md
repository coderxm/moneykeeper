# moneykeeper 1.0.0
## 小码理财moneykeeper（xiaomalicai）资金管理工具

该文件工具在命令行窗口执行，简单高效，以记录使用者现在所拥有的资金为目的，可随时修改更新。
可修改再编译生成新可执行文件。因为C源文件的顺利编译和执行与moneykeeper所在的文件目录有关，
需要在相关的编译器中修改源文件中data.txt的文件路径url。
```
frp = fopen(url,"r");
```
(The file or tool is executed in the command line window, it is simple and efficient, 
and can be modified and updated at any time for the purpose of recording the funds currently 
owned by the user.Can be modified and then compiled to generate a new executable file.Because 
the smooth compilation and execution of C source files is related to the file directory where 
moneykeeper is located, 6 Need to modify the file path url of data.txt in the source file 
in the relevant compiler）

### 项目目录content
```
 data.txt 资金数据(money data for bank-platform)
 main.c 源文件(C source)
 main.exe*（moneykeeper.exe）
 main.o
 Makefile.win
 MK.exe*
 MK.ico
 MK.layout
```

