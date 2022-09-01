/*
* sequence_list (数据结构-顺序表)
*
* @author ideallove
* @since 2022-08-31
* @update 2022-08-31
*/
#include <iostream>
#define MaxSize 100     // 定义线性表的最大长度
#define ElemType int    // 可以根据需求自定义
using namespace std;

// 顺序表数据结构 静态分配
typedef struct {
	/* ElemType是数据结构的书上为了说明问题而用的一个词。它是element type（“元素的类型”）的简化体。*/
	ElemType data[MaxSize]; // 顺序表的元素
	int length;             // 顺序表的当前长度
}SqList;                    // 顺序表的类型定义

// 顺序表数据结构 动态分配
typedef struct {
	ElemType* data; // 指示动态分配数组的指针
	int maxSize;	// 数组的最大容量
	int length;     // 数组的当前个数
}SeqList;           // 动态分配数组顺序表的类型定义

void InitList(SeqList& L);
int GetLength(SeqList& L);
void PrintList(SeqList& L);
bool CreateList(SeqList& L, int n);
bool CreateList(SeqList& L, int n, bool boolean);//重载：预设
bool ListInsert(SeqList& L, int i, ElemType e);
bool ListDelete(SeqList& L, int i);
int LocateElem(SeqList& L, ElemType e);

bool Del_Min(SeqList& L, ElemType& value);
void Reverse(SeqList& L);
void Del_ValueEqX(SeqList& L, ElemType x);//删除：所有值为x的数据元素

/*
* 主函数
*/
int main() {
	cout << "Hello World!" << endl;

	SeqList L;
	InitList(L);
	bool createList = CreateList(L, 10, true);
	int listLength = GetLength(L);
	PrintList(L);
	// 测试Del_Min
	//ElemType value;
	//Del_Min(L, value);
	//cout << value << endl;
	//PrintList(L);
	// 测试翻转
	Reverse(L);
	PrintList(L);

	cout << "ENDING" << endl;
}


/*
* 顺序表 初始化
* 创建一个空的顺序表
*/
void InitList(SeqList& L) {
	// C++的初始动态分配语句
	L.data = new ElemType[MaxSize]; // 为顺序表分配一个大小为MaxSize的数组空间
	if (!L.data) {
		exit(OVERFLOW);             // 存储空间分配失败
	}
	L.maxSize = MaxSize;
	L.length = 0;                   // 空表长度为0
}

/*
* 顺序表 创建
* 创建一个长度为n的顺序表
* @param L 顺序表L
* @param n 长度n
*/
bool CreateList(SeqList& L, int n) {
	if (n<0 || n>MaxSize) {	// 判断n的值是否处于正常范围内
		return false;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i + 1 << "个元素：";
			cin >> L.data[i];
			L.length++;	// 长度一个一个涨
		}
	}
	return true;
}

/*
* 顺序表 创建
* 创建一个长度为n的顺序表
* @param L 顺序表L
* @param n 长度n
* @param boolean 如果为true则使用预设
*/
bool CreateList(SeqList& L, int n, bool boolean) {
	if (n<0 || n>MaxSize) {	// 判断n的值是否处于正常范围内
		return false;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			L.data[i] = (i + 1) * 10;
			L.length++;	// 长度一个一个涨
		}
	}
	return true;
}

/*
* 顺序表 插入操作
* 在顺序表L的第i个位置插入新元素e
* @param L 顺序表L
* @param i 第i个位置
* @param e 新元素e
* @return bool
*/
bool ListInsert(SeqList& L, int i, ElemType e) {
	// 判断i的范围是否有效
	if (i<1 || i>L.length + 1) {
		return false;	//插入位置不合法
	}
	// 当前存储空间已满，不再插入
	if (L.length == MaxSize) {
		return false;
	}
	// 将第i个元素及之后的元素后移
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;	// 在位置i处放入e
	L.length++;			// 线性表长度+1
	return true;
}

/*
* 顺序表 删除操作
* 删除顺序表L的第i个元素
* @param L 顺序表L
* @param i 第i个位置
* @return bool
*/
bool ListDelete(SeqList& L, int i) {
	// 判断i的范围是否有效
	if (i<1 || i>L.length) {
		return false;
	}
	// 打印被删除的元素的值
	ElemType e = L.data[i - 1];
	cout << "deleted element: " << e << endl;
	// 将第i个位置后的元素前移1位
	// 第一轮的时候就删除了第i个位置(下标i-1)的元素
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	// 线性表的长度-1
	L.length--;
	return true;
}

/*
* 顺序表 查找指定元素
* @param L 顺序表L
* @param e 需要查找的元素的值
* @return 查找到的位置，0即未查到
*/
int LocateElem(SeqList& L, ElemType e) {
	// 从顺序表头开始顺序对比，返回其位序i+1
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	// 退出循环即查找失败，返回0
	return 0;
}

/*
* 顺序表 获取数组长度
* @param L 顺序表L
* @return 数组长度
*/
int GetLength(SeqList& L) {
	cout << "SeqList length: " << L.length << endl;
	return L.length;
}

/*
* 顺序表 打印
* @param L 顺序表L
*/
void PrintList(SeqList& L)
{
	cout << "当前顺序表的所有元素分别为：" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << "第" << i + 1 << "个元素为：" << L.data[i] << endl;
	}
}

/*
* 顺序表：删除最小值并返回，用最后一个元素填补
* @param &L 顺序表L
* @param &value 引用型参数返回
*/
bool Del_Min(SeqList& L, ElemType& value) {
	// 使用引用型参数value返回值
	// 若删除成功返回true，否则返回false
	if (L.length == 0) {
		return false;	//表空，终止
	}
	value = L.data[0];	// 初值设置为表头
	int pos = 0;	// 假设0号元素最小
	for (int i = 0; i < L.length; i++) {
		// 循环：寻找最小值
		if (L.data[i] < value) {
			// 让value记忆当前具有最小值的元素
			value = L.data[i];
			pos = i;	// 记录位置
		}
	}
	L.data[pos] = L.data[L.length - 1];	// 空出的位置由最后一个元素填补
	L.length--;	// 表长度-1
	return true;
}

/*
* 顺序表：翻转
* @param &L 顺序表L
*/
void Reverse(SeqList& L) {
	ElemType temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}

/*
* 顺序表：删除：所有值为x的数据元素
* @param &L 顺序表L
* @param x value
*/
void Del_ValueEqX(SeqList& L, ElemType x) {
	int k = 0;	// k记录值不等于x的元素个数
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

/*
* 顺序表：合并：将有序顺序表A与B合并为一个新的顺序表C
* @param &L 顺序表L
* @param A 有序顺序表A
* @param B 有序顺序表B
* @param &C 引用 有序顺序表C
* @return boolean
*/
bool Merge(SeqList A, SeqList B, SeqList& C) {
	if (A.length+B.length>C.maxSize) {
		// 大于顺序表的最大长度则失败
		return false;
	}
	int i = 0, j = 0, k = 0;
	while (i<A.length&&i<B.length) {
		// 循环比较
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	// 比较剩余长度
	while (i < A.length)
		C.data[k++] = A.data[i++];
	while (j < B.length)
		C.data[k++] = B.data[j++];
	// 设置C的实际长度
	C.length = k;
	return true;
}