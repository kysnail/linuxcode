## Tag Object

            49e11..
    ---------------------
    |tag        |size   |
    ---------------------
    |object     |ae668  |
    |type       |commit |
    |tagger     |Scott  |
    ---------------------
    |my tag message that|
    |explains this tag  |
    ---------------------

A tag object contains an object name (called simply 'object'), object type, tag name, the name of the person ("tagger") who created the tag, and a message, which may contain a signature, as can be seen using git `cat-file`:

    kysnail@mydebianwork:super$ git tag mytag 0ed40fb8121f35c0ebae483478ec168a043cb3b9
    kysnail@mydebianwork:super$ git cat-file tag mytag
    fatal: git cat-file mytag: bad file
    kysnail@mydebianwork:super$ git tag -d mytag
    Deleted tag 'mytag' (was 0ed40fb)
    kysnail@mydebianwork:super$ git tag -a mytag 0ed40fb8121f35c0ebae483478ec168a043cb3b9
    kysnail@mydebianwork:super$ git cat-file tag mytag
    object 0ed40fb8121f35c0ebae483478ec168a043cb3b9
    type commit
    tag mytag
    tagger kysnail <kysnail@mydebianwork.com> 1340086920 +0800

    my first tag.
    kysnail@mydebianwork:super$ 

## 注意
`git tag` 同样也可以用来创建“轻量级的标签”（lightweight tags），但它们并不是标签对象，而只是一些以 **refs/tags** 开头的引用罢了。
