 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct node {
	 int data;
	 struct node *next;
 }node;

 
 #define LOG_DEBUG 0
 
 int add_to_top(node** head, int data);
 int add_ascending(node** head, int data);
 void sord_ascending(node** head);
 node* merge_list(node** l1, node** l2);
 void print_list(node *head);
 node* findmin(node *start);
 void swap(node *p1, node *p2, node **start);
 void sort(node **start);
 
  
 
 int main(void)
 {
	 printf("Linked list operations\n");
	 
	 node *list1 = NULL;
	 node *list2 = NULL;
	 for(int i = 0, j = 10;i < 10;i++, j--)
	 {
	 int ret = add_to_top(&list1, i);
	 ret = add_to_top(&list2, j);
	 if(ret < 0)
	 {
		 printf("Error adding to list\n");
	 }
	 }
	 node *list = merge_list(&list1, &list2);
	 print_list(list);

	 return 0;
 }
 
 node* merge_list(node** l1, node** l2)
 {
	node *p1 = *l1;
	node *p2 = *l2;	
	node *head = NULL;
	
	while((p1 != NULL) || (p2 != NULL))
	{
		if(p1 != NULL)
		{
			add_to_top(&head, p1->data);
			p1 = p1->next;
		}
		if(p2 != NULL)
		{
			add_to_top(&head, p2->data);
			p2 = p2->next;
		}
	}
	return head;
	
 }
 
 void print_list(node *head){
	 printf("List item:%d\n", head->data);
	 node* temp = head;
	 while(temp != NULL)
	 {
		printf("%d \n", temp->data); 
		temp = temp->next;
	 }
	 
 }
 
 int add_to_top(node** head, int data) {
	 node *new_node = (node *)malloc(sizeof(node));
	 int ret = 0;
	 if(new_node == NULL)
	 {
		 ret = -1;
	 }
	 else{
		 new_node->data = data;
		 if(*head == NULL)
		 {
			new_node->next = NULL;
			*head = new_node; 
			ret = 0;
		 }
		 else
		 {
			 new_node->next = *head;
			 *head = new_node;
			 ret = 0;
		 }
	 }
	 #ifdef LOG_DEBUG
	 printf("new node data: %d \n",new_node->data);
	 #endif
	 return ret;
 }
 void sord_ascending(node** head){
	node *curr = *head;	
	while(curr->next != NULL)
	{
		node *curr_iter = curr;
		node *next = curr_iter;
		while(curr_iter->next != NULL)
		{
			#ifdef LOG_DEBUG
	 printf("curr node data: %d \n",curr_iter->data);
	 #endif
			next = curr_iter->next;
			if(curr_iter->data >= curr_iter->next->data)
			{
				node *temp = curr_iter->next;
				curr_iter->next = temp->next ;
			temp->next = curr_iter;		// Add at the end 3. _->3
			curr_iter = temp;
			}
			else{
				curr_iter = next;
			}
			
		}
		curr = curr->next;
	}			 
	 
 }
 int add_ascending(node** head, int data) {
	 node *new_node = (node *)malloc(sizeof(node));
	 int ret = 0;
	 if(new_node == NULL)
	 {
		 ret = -1;
	 }
	 else{
		 new_node->data = data;
		 if(*head == NULL)
		 {
			new_node->next = NULL;
			*head = new_node; 
			ret = 0;
		 }
		 else
		 {
			 node *curr = *head;
			 node *prev = *head;
			 while(curr->next != NULL)
			 {
				 prev = curr;
				 curr = curr->next;
				 if(prev->data >=  curr->data)
				 {
					prev->next = curr->next;		// Add at the end
					curr = prev;
				 }
				 
			 }
			 ret = 0;
		 }
	 }
	 #ifdef LOG_DEBUG
	 printf("new node data: %d \n",new_node->data);
	 #endif
	 return ret;
 }
 
// void sort(node **start)
//{
//    if (((*start)->next == NULL) || (*start == NULL))
//    {
//        return;
//    }
//    node *min = findmin(*start);
//    swap(*start, min, start);
//    sort(&((*start)->next));
//}
//
//void swap(node *p1, node *p2, node **start)
//{
//    node *p1pre = NULL;
//    node *p1curr = *start;
//    while (p1curr!=p1)
//    {
//        p1pre = p1curr;
//        p1curr = p1curr->next;
//    }
//    node *p2pre = NULL;
//    node *p2curr = *start;
//    while (p2curr != p2)
//    {
//        p2pre = p2curr;
//        p2curr = p2curr->next;
//    }
//    if (p1pre != NULL)
//    {
//        p1pre->next = p2curr;
//    }
//    else
//    {
//        *start = p2curr;
//    }
//    if (p2pre != NULL)
//    {
//        p2pre->next = p1curr;
//    }
//    else
//    {
//        *start = p1curr;
//    }
//    node *temp = p2curr->next;
//    p2curr->next = p1curr->next;
//    p1curr->next = temp;
//}
//
//node* findmin(node *start)
//{
//    int flag = 0;
//    if (start == NULL)
//    {
//        cout << "list is empty" << endl;
//    }
//    else
//    {
//        node *curr = start->next;
//        node *min = start;
//        while (curr->next != NULL)
//        {
//            if (min->value > curr->value)
//            {
//                min = curr;
//                flag++;
//            }
//            curr = curr->next;
//        }
//        if ((curr->next == NULL) && (min->value > curr->value))
//        {
//            min = curr;
//            flag++;
//        }
//        if (flag > 0)
//        {
//            return min;
//        }
//    }
//}
//