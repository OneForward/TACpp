#include <iostream>
#include <cstdio>

using namespace std;

void bubbleSort(int* A, int n) {
    for (int i=n-1; i>=0; --i) {
        bool exist_swap = false;
        for (int j=0; j<i; ++j) {
            if (A[j] > A[j+1]) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (! exist_swap) break;
    }
}

void dispArray(int* A, int n) {
    for (int i = 0; i < n; ++i) { 
        cout << A[i] << " ";
    }
    cout << endl;
}


int len, prices[1005];

void inputPrices() {
    len = 0; int x = 0;
    while (cin >> x && x != -1) {
        prices[len++] = x;
    }
}

void dispPrices() {
    dispArray(prices, len);
}

void sortedPrices() {
    int tmpPrices[1005];
    for (int i = 0; i < len; ++i) { 
        tmpPrices[i] = prices[i];
    }
    bubbleSort(tmpPrices, len);
    dispArray(tmpPrices, len);
}

void argMaxMin() {
    int maxVal = prices[0], maxIndex = 0, 
        minVal = prices[0], minIndex = 0;
    for (int i = 1; i < len; ++i) { 
        if (prices[i] > maxVal) maxVal = prices[i], maxIndex = i;
        if (prices[i] < minVal) minVal = prices[i], minIndex = i;
    }
    // cout << maxIndex << " " << minIndex << endl;
    cout << minIndex << " " << maxIndex << endl;
}

void maxProfitByOneTrade() {
    int maxProfit = 0;
    for (int i = 0; i < len; ++i) { 
        for (int j = i+1; j < len; ++j) { 
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }
    }
    cout << maxProfit << endl;
}

void maxProfitByMultipleTrade() {
    int f[1005];
    // f[i] = max(p[i] - p[k] + f[k-1]) for k = 0...i-1
    for (int i = 0; i < len; ++i) { 
        int maxVal = 0;
        for (int k = 1; k < i; ++k) { 
            maxVal = prices[i] - prices[k] + f[k-1];
        }
        f[i] = max(maxVal, prices[i] - prices[0]);
    }

    int maxProfit = 0;
    for (int i = 0; i < len; ++i) { 
        maxProfit = max(maxProfit, f[i]);
    }
    cout << maxProfit << endl;
}

void selectFunc(int i) {
    using Func = void (*)();
    Func funcs[] = {nullptr, inputPrices, dispPrices, sortedPrices, 
                    argMaxMin, maxProfitByOneTrade, 
                    maxProfitByMultipleTrade};
    
    funcs[i]();
}


void showOption(){
    cout<<"欢迎使用股票分析系统："<<endl;
    cout<<"1--输入股票价格序列"<<endl;
    cout<<"2--查询股票价格"<<endl;
    cout<<"3--输出升序的股票价格序列"<<endl;
    cout<<"4--输出最大值和最小值的日期"<<endl;
    cout<<"5--一笔交易的最大利润"<<endl;
    cout<<"6--多笔交易的最大利润"<<endl;
    cout<<"7--退出"<<endl;
}

// Your code here

int main()
{
    showOption();

    int op;
    while (true)
    {
        cin >> op;
        if (op == 7) return 0;
        selectFunc(op);
    }
    
}