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

struct Stock
{
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

    void dispSortedPrices() {
        int tmpPrices[1005];
        for (int i = 0; i < len; ++i) { 
            tmpPrices[i] = prices[i];
        }
        bubbleSort(tmpPrices, len);
        dispArray(tmpPrices, len);
    }

    void dispArgMaxMin() {
        int maxVal = prices[0], maxIndex = 0, 
            minVal = prices[0], minIndex = 0;
        for (int i = 1; i < len; ++i) { 
            if (prices[i] > maxVal) maxVal = prices[i], maxIndex = i;
            if (prices[i] < minVal) minVal = prices[i], minIndex = i;
        }
        // cout << maxIndex << " " << minIndex << endl;
        cout << minIndex << " " << maxIndex << endl;
    }

    void dispMaxProfitByOneTrade() {
        int maxProfit = 0;
        for (int i = 0; i < len; ++i) { 
            for (int j = i+1; j < len; ++j) { 
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        cout << maxProfit << endl;
    }

    void dispMaxProfitByMultipleTrade() {
        // buy: 记录到第 i 天的时候最多赚多少（当天只允许买入或者不交易）
        // sell: 记录到第 i 天的时候最多赚多少（当天只允许卖出或者不交易）
        int buy = -0x7fffffff, sell = 0;
        for (int i = 0; i < len; i++)
        {
            auto x = prices[i];
            buy = max(buy, sell - x);
            sell = max(sell, buy + x);
        }
        cout << sell << endl;
    }
};

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

    Stock stock;
    int op;
    while (true)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            stock.inputPrices();
            break;
        case 2:
            stock.dispPrices();
            break;
        case 3:
            stock.dispSortedPrices();
            break;
        case 4:
            stock.dispArgMaxMin();
            break;
        case 5:
            stock.dispMaxProfitByOneTrade();
            break;
        case 6:
            stock.dispMaxProfitByMultipleTrade();
            break;
        default:
            return 0;
        }
    }
    
}