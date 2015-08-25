#include <stdio.h>
#include "dlist.h"

struct int_node {
        int val;
        struct list_head list;
};

int main()
{
        struct list_head head, *plist;
        struct int_node a, b;
        struct int_node * pos;//!!! pos and plist 's type

        struct int_node *node = NULL;
        a.val = 2;
        b.val = 3;

        INIT_LIST_HEAD(&head);
        list_add(&a.list, &head);
        list_add(&b.list, &head);

        list_for_each(plist, &head) 
        {
                node = list_entry(plist, struct int_node, list);
                printf("val = %d\n", node->val);
        }
        list_for_each_entry(pos ,struct int_node, &head,list) 
        {

                printf("each entry val = %d\n", pos->val);
        }

        /*
#define list_for_each(pos, head) \
for (pos = (head)->next; pos != (head); pos = pos->next)


         */

        /*
#define list_for_each_entry(pos, head, member)              \
for (pos = list_entry((head)->next, typeof(*pos), member);  \
&pos->member != (head);    \
pos = list_entry(pos->member.next, typeof(*pos), member))
         */

        /*


#define list_for_each_entry(pos,pos_type, head, member)             \
for (pos = list_entry((head)->next, pos_type, member);  \
&pos->member != (head);    \
pos = list_entry(pos->member.next, pos_type, member))

         */
        return 0;
}
