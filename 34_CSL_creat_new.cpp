#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class node *addtoEmpty(int data)
{
    class node *temp = (class node *)malloc((sizeof(struct node)));
    temp->data = data;
    temp->next = temp;
    return temp;
}
class node *addtoEnd(class node *tail, int data)
{
    class node *newp = (class node *)malloc((sizeof(struct node)));
    newp->data = data;
    newp->next = NULL;
    newp->next = tail->next;
    tail->next = newp;
    tail = tail->next;
    return tail;
}
class node *createList(class node *tail)
{
    int i, n, data;
    cout << "Enter the number of nodes " << endl;
    cin >> n;
    if (n == 0)
    {
        return tail;
    }
    cout << "Enter the element 1 " << endl;
    cin >> data;
    tail = addtoEmpty(data);
    for (int i = 1; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << endl;
        cin >> data;
        tail = addtoEnd(tail, data);
    }
    return tail;
}
void printlist(class node *tail)
{
    if (tail == NULL)
    {
        cout << "No node in the list" << endl;
    }
    else
    {
        class node *p = tail->next;
        do
        {
            cout << " " << p->data;
            p = p->next;
        } while (p != tail->next);
    }
}
int main()
{
    class node *tail = NULL;
    // tail = addtoEmpty(34);
    // tail = addtoEnd(tail, 56);
    // tail = addtoEnd(tail, 56);
    // tail = addtoEnd(tail, 56);
    // printlist(tail);
    tail = createList(tail);
    printlist(tail);

    return 0;
}
