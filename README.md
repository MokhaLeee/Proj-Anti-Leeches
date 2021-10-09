# Proj-Anti-Leeches：
### 一个适用于FE8J(Also FE8-cn)的反二改项目
---

## 郑重提醒
本项目完全开源，[Totally free on github](https://github.com/MokhaLeee/Proj-Anti-Leeches) 

## 何谓反二改
他人盗用原作品，单纯修改成长率、角色数值等随后发布的作品称为二改作品。
本项目旨在游戏开始阶段引入对一些数值的检测过程，在检测到存在二改迹象后，游戏将自行停止运行。

## 如何使用

### 如果你使用EA的方法烧录的话
- 打开Buildfile.txt，并将第11行，```#define FreeSpace $EF2F20```部分取消注释；
- 随后请参考我的[烧录教程](https://www.bilibili.com/video/BV1hq4y1P7am)，将Event Assembler与你的rom（需重命名为FE8_clean.gba）并放置在文件夹中，随后双击```MAKE HACK.cmd```

### 如果你使用FEBuilder烧录的话
- ```执行``` - ```事件由汇编程序添加``` - ```选择另一个文件```，选择Buildfile.txt后，```阅读脚本```。