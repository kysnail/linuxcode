/**
 * Insert a node in double linked list. 
 */
int InsertDList(DLinkList head, int i, DataType e)
{
        DLinkNode *p, *s;
        int j;
        p = head->next; // with head node

        for (int j = 1; j != i && p != head; j++)
        {
                 p = p->next
        }

        if (j != i)
        {
                printf("wrong location\n");
                return 0;
        }

        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        if (!s)
        {
                return -1;
        }

        s->data = e;
        // core ops
        p->prior->next = s;
        s->prior = p->prior;
        s->next = p;
        p->prior = s;

        return 1;
}