#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

using VI = vector<int>;
#define ALL(A) A.begin(),A.end()

void dispArray(const VI& v) {
    for (auto&& x: v) { 
        cout << x << " ";
    }
    cout << endl;
}

struct Stock
{
    VI prices;

    void inputPrices() {
        int x = 0;
        while (cin >> x && x != -1) {
            prices.push_back(x);
        }
    }

    void dispPrices() {
        dispArray(prices);
    }

    void dispSortedPrices() {
        auto v = prices;
        sort(ALL(v));
        dispArray(v);
    }

    void dispArgMaxMin() {
        int maxIndex = 0, minIndex = 0;
        for (int i = 0; i < (int)prices.size(); ++i) { 
            if (prices[i] > prices[maxIndex])  maxIndex = i;
            if (prices[i] < prices[minIndex])  minIndex = i;
        }
        cout << minIndex << " " << maxIndex << endl;
    }

    void dispMaxProfitByOneTrade() {
        // sell[i]: 到第 i 天为止最后一笔交易是卖出股票（未必是第 i 天卖出），所获得的最大收益
        // buy[i] : 到第 i 天为止最后一笔交易是买入股票（未必是第 i 天买入），所获得的最大收益
        int buy = INT_MIN, sell = 0;
        for (auto&& x: prices)
        {
            buy = max(buy, -x);
            sell = buy + x;
        }
        cout << sell << endl;
    }

    void dispMaxProfitByMultipleTrade() {
        // sell[i]: 到第 i 天为止最后一笔交易是卖出股票（未必是第 i 天卖出），所获得的最大收益
        // buy[i] : 到第 i 天为止最后一笔交易是买入股票（未必是第 i 天买入），所获得的最大收益
        int buy = INT_MIN, sell = 0;
        for (auto&& x: prices)
        {
            buy = max(buy, sell - x);
            sell = buy + x;
        }
        cout << sell << endl;
    }
    
    void selectFunc(int i) {
        using Func = void (Stock::*)(); // gcc7.2.0 
        Func funcs[] = {nullptr, &Stock::inputPrices, &Stock::dispPrices, 
                        &Stock::dispSortedPrices, &Stock::dispArgMaxMin, 
                        &Stock::dispMaxProfitByOneTrade, 
                        &Stock::dispMaxProfitByMultipleTrade};
        
        (this->*funcs[i])();
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
        if (op == 7) return 0;
        stock.selectFunc(op);
    }
    
}