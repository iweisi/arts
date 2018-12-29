# 编写领域语言
[原文链接](https://97-things-every-x-should-know.gitbooks.io/97-things-every-programmer-should-know/content/en/thing_11/)

两个代码库。其中一个是这样的：
```java
if (portfolioIdsByTraderId.get(trader.getId())
  .containsKey(portfolio.getId())) {...}
```
你抓破头皮，想要搞懂这段代码要做什么。看起来像是从trader对象中取出一个ID，通过一张表查找另一张表，好吧，上面代码就是表中表的玩法，但好像又是在比较portfolio对象是否存在这张表中。哎呀，抓耳挠腮呀。继续从portfolioIdsByTraderId中寻找线索:
```java
Map<int, Map<int, int>> portfolioIdsByTraderId;
```
渐渐的你发现，这应该和trader对象是否要访问某个特定portfolio对象有关。毫无疑问，你会发现更多相同的代码片段，或者更多看着像但很隐蔽的不同的代码片段——不论什么时候都要注意trader是否在访问某个特殊portfolio。

在另一个代码库：
```java
if (trader.canView(portfolio)) {...}
```
这次不用挠头了。有不需要知道trader内部在干嘛。或许里边就有藏着各种表。但那是trader的业务，和你没关系。

现在，你更希望用哪个代码库完成工作？

从前我们只有很基础的数据结构：bit和char(当然还有bytes，我们假装用于字母和标点符号)。小数点比较棘手，因为我们的10个数字在二进制中不好弄，所以我们又为浮点类型扩充了一些内存长度。这次有了array数组和string(其实就是不同的数组)。然后我们又增加了堆栈、队列、哈希、链表、跳表以及大量的根本不存在真实世界的数据结构。“计算机科学”就是花大量的时间把真实世界映射到我们限定的数据结构中。真正的大师甚至能够记住他们是如何做到的。

我们有了user类型定义！OK，这不是什么新闻，但它的确改变了游戏规则。如果你的业务领域包含像traders和portfolios的概念，你可以对它们建模，称之为，Trader和Portfolio。但比这更重要的，你也要会给它们两者之间的关系进行建模。