struct BOARD        // 游戏底板结构，表示每个点所具有的属性。
{
    int var;        // 当前状态只有 0 和 1，1 表示此点已被占用。
    int color;      // 颜色，游戏底板的每个点可以拥有不同的颜色，增强美观性。
}Table_board[Vertical_boxs][Horizontal_boxs];

struct SHAPE
{
    /*
     * 一个字节是 8 位，用每 4 位表示游戏方块中的一行，
     * 例如 box[0]="0x88", box[1]="0xc0" 表示的是：
     * 1000
     * 1000
     * 1100
     * 0000
     */
    char box[2];
    int color;      // 每个方块的颜色
    int next;       // 下个方块的编号
}

// 初始化方块内容，即定义 MAX_BOX 个 SHAPE 类型的结构数组，并初始化。
struct SHAPE shapes[MAX_BOX] =
{
    /*
     *  □       □ □ □  □ □          □    
     *  □       □        □      □ □ □ 
     *  □□               □  
     */
    { 0x88, 0xc0,   CYAN,   1},
    { 0xe8, 0x0,    CYAN,   2},
    { 0xc4, 0x40,   CYAN,   3},
    { 0x2e, 0x0,    CYAN,   4},

}
