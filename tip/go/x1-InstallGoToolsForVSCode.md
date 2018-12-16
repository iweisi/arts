# VSCode安装GO语言依赖工具
由于vscode对go语言的支持还是hin不错滴，所以我日常学习go都用vscode，但这货有个毛病，各种lint、补全、nav、调试都依赖go语言的其他扩展工具，如果安装补全，会给出类似提示：
```
The "gocode" command is not available. Use "go get -v github.com/mdempsky/gocode" to install.
```
但如果按照vscode的提示点击“安装”后，经过漫长等待，会迎来进一步提示：
```
gocode:
Error: Command failed: /usr/local/go/bin/go get -u -v github.com/mdempsky/gocode
github.com/mdempsky/gocode (download)
Fetching https://golang.org/x/tools/go/gcexportdata?go-get=1
https fetch failed: Get https://golang.org/x/tools/go/gcexportdata?go-get=1: dial tcp 216.239.37.1:443: i/o timeout
package golang.org/x/tools/go/gcexportdata: unrecognized import path "golang.org/x/tools/go/gcexportdata" (https fetch: Get https://golang.org/x/tools/go/gcexportdata?go-get=1: dial tcp 216.239.37.1:443: i/o timeout)
```
What's the fuuuuuuu!!!

必须说明我是在科学上网的前提下执行的安装命令，所以猜测不是网络问题，具体原因没深究，我参考了[官方指导](https://github.com/Microsoft/vscode-go/wiki/Go-tools-that-the-Go-extension-depends-on)以及[一篇博文](http://www.pythonsite.com/?p=429)解决的该问题，博客写得有点绕，我挑简单的总结一下。

## 解决方案
从官方文档中可以明确，VSCode依赖的几款工具完成不同功能：

|名称|描述|链接
|-|-|-|
|gocode|代码自动补全|https://github.com/mdempsky/gocode
|go-outline|在当前文件中查找|https://github.com/ramya-rao-a/go-outline
|go-symbols|在项目路径下查找|https://github.com/acroca/go-symbols
|gopkgs|自动补全未导入包|https://github.com/uudashr/gopkgs
|guru|查询所有引用|https://golang.org/x/tools/cmd/guru
|gorename|重命名符号|https://golang.org/x/tools/cmd/gorename
|goreturns|格式化代码|https://github.com/sqs/goreturns
|godef|跳转到声明|https://github.com/rogpeppe/godef
|godoc|鼠标悬浮时文档提示|https://golang.org/x/tools/cmd/godoc
|golint|就是lint|https://golang.org/x/lint/golint
|dlv|调试功能|https://github.com/derekparker/delve/tree/master/cmd/dlv
|gomodifytags|修改结构体标签|https://github.com/fatih/gomodifytags
|goplay|运行当前go文件|https://github.com/haya14busa/goplay/
|impl|新建接口|https://github.com/josharian/impl
|gotype-live|类型诊断|https://github.com/tylerb/gotype-live
|gotests|单元测试|https://github.com/cweill/gotests/
|go-langserver|语言服务|https://github.com/sourcegraph/go-langserver
|filstruct|结构体成员默认值|https://github.com/davidrjenni/reftools/tree/master/cmd/fillstruct

以上的工具可以有选择地安装，但为了开发过程中不要出什么岔子，我一般选择全部安装，很不幸的是安装过程中80%的工具会出现`timeout`的提示。  
先来看看每个工具的安装命令：
```
go get -u -v github.com/ramya-rao-a/go-outline
go get -u -v github.com/acroca/go-symbols
go get -u -v github.com/mdempsky/gocode
go get -u -v github.com/rogpeppe/godef
go get -u -v golang.org/x/tools/cmd/godoc
go get -u -v github.com/zmb3/gogetdoc
go get -u -v golang.org/x/lint/golint
go get -u -v github.com/fatih/gomodifytags
go get -u -v golang.org/x/tools/cmd/gorename
go get -u -v sourcegraph.com/sqs/goreturns
go get -u -v golang.org/x/tools/cmd/goimports
go get -u -v github.com/cweill/gotests/...
go get -u -v golang.org/x/tools/cmd/guru
go get -u -v github.com/josharian/impl
go get -u -v github.com/haya14busa/goplay/cmd/goplay
go get -u -v github.com/uudashr/gopkgs/cmd/gopkgs
go get -u -v github.com/davidrjenni/reftools/cmd/fillstruct
go get -u -v github.com/alecthomas/gometalinter
gometalinter --install
```

为了统一每个人的开发环境，下文中`GOPATH`表示自己电脑go的安装路径，例如我的电脑默认安装路径为`~/go`，如果没有的话建议先执行命令`export GOPATH=~/go`，Windows用户...👋

### 安装步骤
1. 创建目录`$GOPATH/src/golang.org/x`，并切换到该目录
```bash
$ mkdir -p $GOPATH/src/golang.org/x/
$ cd $GOPATH/src/golang.org/x/
```
2. 克隆工具源码
```bash
git clone https://github.com/golang/tools.git
```
3. 安装gometalinter
```bash
go get -u -v github.com/alecthomas/gometalinter
```
4. 安装全部工具
```bash
$GOPATH/bin/gometalinter --install
```
5. 继承到系统环境中

由于我是在用户目录下临时安装的，真正的GO环境是`/usr/local/go`，所以最后一步无比注意，把`~/go/bin`下面生成的所有执行文件拷贝到系统环境中
```bash
sudo cp -af go/bin/* /usr/local/go/bin/
```

解释一下，按照官方的套路，我们很可能会在访问golang.org的时候挂掉，原因你懂的，所以只能曲线救国，先从github上把tools全套的下载到本地，在通过gometalinter一键安装。

打完收工！