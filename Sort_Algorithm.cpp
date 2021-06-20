#include <bits/stdc++.h>
using namespace std;
int len;  // 数组长度
int arr[10000];

// 打印数组
void print(int arr[]) {
    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 使用随机数生成数组
void createArray(int arr[]) {
    cout << "请输入要生成的数组的长度" << endl;
    cin >> len;
    // 输入的数组长度必须大于0
    while(len <= 0) {
        cout << "输入的数组长度不合法，请重新输入" << endl;
        cin >> len;
    }
    int a, b;
    cout << "请输入要生成的数的最小值" << endl;
    cin >> a;
    cout << "请输入要生成的数的最大值" << endl;
    cin >> b;
    if(a > b) swap(a, b);
    int index = 0;
    int n = len;
    while(n--) {
        arr[index++] = (rand() % (b - a + 1)) + a;
    }
    cout << "未排序" << endl;
    print(arr);
}

// 冒泡排序
// 通过相邻元素的比较和交换，使得每一趟循环都能找到未有序数组的最大值或最小值
// 最好：O(n)，只冒泡一次数组就有序的情况。
// 最坏：O(n^2)
// 平均：O(n^2)
void bubbleSort(int arr[]) 
{
   	for(int i = 0;i<len;i++)
	{
        for(int j =1;j<len-i;++j)
		{
            if(arr[j-1]>arr[j]) 
				swap(arr[j-1],arr[j]);
		}
	}
}

// 双向冒泡
// 普通的冒泡排序在一趟循环中只能找出一个最大值或最小值，双向冒泡则是多一轮循环既找出最大值也找出最小值
void bubbleSort_2way(int arr[]) 
{
	int l=0,r=len-1,s=1,i;
  	while(l<r) 
	{
    	for(i=l;i<r;i++) 
		{
    		if(arr[i]>arr[i+1]) 
			{
    		    swap(arr[i], arr[i+1]);
    		    s=i;
    		}
    	}
    r=s;
    for(i=r-1;i>=l;i--) 
	{ 
      	if(arr[i]>arr[i+1]) 
		  	{
        	swap(arr[i],arr[i+1]);
        	s=i+1;
       		}
    	}
    l=s;
  	}  
}
void selectSort(int arr[]) 
{
     
	int min;
	for(int i=0; i<len-1;i++)
	{
	    min=i;
	    for(int j=i+1;j<len;j++)
		{
		    if(arr[j]<arr[min])
				min=j;
		
		}
		swap(arr[i],arr[min]);
	}
}

// 插入排序
// 以第一个元素作为有序数组，其后的元素通过在这个已有序的数组中找到合适的位置并插入
// 最好：O(n)，原数组已经是升序的
// 最坏：O(n^2)， 原数组已经是降序的
// 平均：O(n^2)
void insertSort(int arr[]) 
{
	int i, j; 
	for (i = 1; i < len; i++) 
        if (arr[i] < arr[i - 1])  
        { 
			int temp = arr[i]; 
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) 
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		} 
}

// 二分插入排序
void binSort(int arr[]) 
{
    
    int i,j;
    i=1;
    while(i<len)
    {
        int x=arr[i];
        int high=0;
        int low=i-1;
        while(high<=low)
        {
            int mid=(high+low)/2;
            if(x<arr[mid])
                low=mid-1;
            else
                high=mid+1;
        }
        for(j=i-1;j>=high;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[high]=x;
        i++;
    }
}

// 快速排序
void quickSort(int arr[], int left, int right) 
{
    	if (left > right) 
	{
		return;
	}

	int i = left;
	int j = right;
	int b = arr[left];
	while(i != j) {
		while(arr[j] >= b && i<j) {
			j--;
		}

		while(arr[i] <= b && i<j) {
			i++;
		}
		
		if(i<j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	arr[left] = arr[i];
	arr[i] = b;

	quickSort(arr, left, i-1);
	quickSort(arr, i+1, right);
}

int main() {
    createArray(arr);
    cout << endl;

    cout << "冒泡排序" << endl;
    bubbleSort(arr);
    print(arr);

    cout << "双向冒泡排序" << endl;
    bubbleSort_2way(arr);
    print(arr);

    cout << "选择排序" << endl;
    selectSort(arr);
    print(arr);

    cout << "插入排序" << endl;
    insertSort(arr);
    print(arr);

    cout << "二分插入排序" << endl;
    binSort(arr);
    print(arr);

    cout << "快速排序" << endl;
    quickSort(arr);
    print(arr);
}
