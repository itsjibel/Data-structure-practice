#include <stdio.h>
#include <vector>
using std::vector;

class COWLL
{
    private:

    protected:
		int list_size = 0;

    public:
		struct node
		{
			int data;
			node *next, *prev;
		} *start;
        void create_node(int val)
		{
			if (start != NULL)
				return;

			node *n;
			n = new(node);
			n->data = val;
			n->next = n;
			start = n;
			list_size++;
		}

		void append(int val)
		{
			if (start == NULL)
				return;
			node *a;
			a = new(node);
			a->data = val;
			a->next = start;
			node *p = start;
			while(1)
			{
				if (p->next == start)
				{
					p->next = a;
					list_size++;
					return;
				}
				p = p->next;
			}
		}

		void pop(int val)
		{
			if (start == NULL)
				return;

			node *p, *l=start;
			p = new(node);
			p->data = val;
			p->next = start;
			while (l->next != start)
				l = l->next;
			l->next = p;
			start = p;
			list_size++;
		}

		void insert(int val, int index)
		{
			if (start == NULL || index < 0 || index > list_size)
				return;

			node *i;
			i = new(node);
			i->data = val;
			node *p = start, *temp;
			int counter=0;
			while (counter < index)
			{
				temp = p;
				p = p->next;
				if (p == start)
					break;
				counter++;
			}
			i->next = p;

			if (counter == 0)
			{
				node *l;
				while (l->next != start)
					l = l->next;
				l->next = i;
				start = i;
			}
			else
				temp->next = i;

			list_size++;
		}

		void pop_back()
		{
			if (start == NULL)
				return;
			node *b = start, *temp;

			while (1)
			{
				if (b->next == start)
				{
					if (b == start)
						start = NULL;
					temp->next = start;
					list_size--;
					delete b;
					return;
				}
				temp = b;
				b = b->next;
			}
		}

		void erase(int index)
		{
			if (start == NULL || index < 0)
				return;

			node *d = start;
			if (index == 0)
			{
				node *l=start;
				while (l->next != start)
					l = l->next;
				l->next = d->next;
				start = d->next;
				list_size--;
				delete d;
				return;
			}

			node *temp;
			int counter=0;
			while(1)
			{
				if (counter == index)
				{
					if (d->next == start)
						temp->next = start;
					temp->next = d->next;
					list_size--;
					delete d;
					return;
				}
				temp = d;
				d = d->next;
				counter++;
				if (d == start)
					return;
			}
		}

        int at(int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return 0;

			node *p = start;
            if (index == 0)
                return p->data;
            else {
                while (p->next != start)
                {
                    if (index == 0)
                    {
                        return p->data;
                    }
					p = p->next;
                    index--;
                }
				return p->data;
            }

			return 0;
		}

        int size()
		{
			return list_size;
		}

        void free_list()
		{
			if (start == NULL)
				return;
			node *d = start;
			while(1)
			{
				node *temp = d->next;
				if (temp != start)
				{
					start = NULL;
					return;
				}
				delete d;
				list_size--;
				d = temp;
			}
			start = NULL;
		}

		// Constructors
		COWLL() {}

		COWLL(int data)
		{
			create_node(data);
		}

		COWLL(vector<int> values)
		{
			create_node(values.front());
			for (int i=1; i<values.size(); i++)
				append(values.at(i));
		}

		// Destructor
		virtual ~COWLL()
		{
			free_list();
		}
};