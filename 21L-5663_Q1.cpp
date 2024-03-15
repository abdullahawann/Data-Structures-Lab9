#include <iostream>
using namespace std;

template<typename k, typename v>
class MinHeap
{
	struct HeapItem
	{
		k key;
		v value;
	};
	int* arr;
	int capacity;
	int totalItems;

public:
	MinHeap()
	{
		arr=NULL;
	}

	MinHeap(int _capacity)
	{
		capacity = _capacity;
		totalItems = 0;
		arr = new int[capacity];
	}

	bool isEmpty() const
	{
		if(arr == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void heapify(int *arra,k ke)
	{
		while(ke >1)
		{
			if(arra[ke/2] > arra[ke])
			{
				swap(arra[ke/2],arra[ke]);
				ke = ke/2;
			}
			else 
			{
				ke = ke/2;
			}
		}
	}

	void insert(k key, v value)
	{
		if(key <= capacity)
		{
			arr[key] = value;
			totalItems++;
		}
		else
		{
			capacity = capacity*2;
			int*temp = arr;
			arr = new int [capacity];
			arr = temp;
			insert(key, value);
		}
		heapify(arr, key);
	}

	void getMin(v& _value)
	{
		if(!isEmpty())
		{
			_value = arr[1];
		}
		else
			cout << "The heap is empty" << endl;
	}

	void deleteMin()
	{
		arr[1] = arr[totalItems];
		totalItems--;
		heapify(arr, totalItems);
		heapify(arr, totalItems-1);
	}

	void Display()
	{
		for(int i=1; i<=totalItems; i++)
		{
			cout << arr[i] <<" ";
		}
	}

	~MinHeap()
	{
		delete []arr;
	}
};

int main()
{
	int c;
	int n;
	cout << "Enter the capacity of the heap : ";
	cin >> c;
	MinHeap<int,int> h(c);
	 
	for(int i=1; i<=c-1; i++)
	{
		cout << "Enter the " << i << " value in heap : ";
		cin >> n;
		h.insert(i, n);
	}
	cout << "The min heap is : ";
	h.Display();
	cout << endl << "The minimum value in heap is : ";
	h.getMin(n);
	cout << n << endl;
	h.deleteMin();
	cout << "The min heap after deleting a specific value is : ";
	h.Display();
	cout << endl;

	system("pause");
	return 0;
}