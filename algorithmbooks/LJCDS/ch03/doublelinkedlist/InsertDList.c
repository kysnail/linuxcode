/**
 * Insert a node in double linked list. 
 */
int InsertDList(DLinkList head, int i, DataType e)
{
        DLinkNode *p, *s;
        int j;
        p = head->next; // with head node

        for (int j = 1; j != i; j++)
        {
                 p = p->next
        }

        if (j != (i - 1))
        {
                printf("wrong location\n");
        }

        *s = (DLinkNode)malloc(sizeof(struct DLinkNode));

        p->prior->next = s;
        s->prior = p->prior;
        s->next = p;
        p->prior = s;
}