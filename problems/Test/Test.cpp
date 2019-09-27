﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums) 
//{
//	if (nums.empty()) return;
//
//	vector<int> vec;
//	for (size_t i = nums.size() - 1; i > 0;)
//	{
//		i--;
//		vec.push_back(nums[i + 1]);
//		if (nums[i] < nums[i + 1])
//		{
//			sort(vec.begin(), vec.end());
//			auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
//			swap(nums[i], *it);
//			for (size_t j = 0; j < vec.size(); j++)
//			{
//				nums[j + i + 1] = vec[j];
//			}
//			break;
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////
int searchInsert(vector<int>& nums, int target) 
{
	size_t low = 0;
	size_t high = nums.size();
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,3,5,6 });
	K.push_back(5);
	ANSWERS.push_back(2);

	TESTS.push_back({ 1,3,5,6 });
	K.push_back(2);
	ANSWERS.push_back(1);

	TESTS.push_back({ 1,3,5,6 });
	K.push_back(7);
	ANSWERS.push_back(4);

	TESTS.push_back({ 1,3,5,6 });
	K.push_back(0);
	ANSWERS.push_back(0);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = searchInsert(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//nextPermutation(TESTS[i]);
		//cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = StringToListNode("[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto i : lists)
//	{
//		cout << i << endl;
//		pHead = sortList(i);
//		cout << pHead << endl;
//		cout << endl;
//	}
//}


