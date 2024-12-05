#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define M_PI 3.141592653589793 // π值

struct ShuttlecockResult {
    double y_net;             // 在網子處的高度
    bool clears_net;          // 是否越過網子
    bool lands_in_valid_area; // 是否落在有效區
};

// 計算羽球的拋物線軌跡，返回相關結果
ShuttlecockResult shuttlecock_trajectory(double angle_deg, double v = 30.0, double h = 1.1, double g = 9.8) {
    double angle_rad = angle_deg * M_PI / 180.0; // 角度轉換為弧度
    double v_x = v * cos(angle_rad);            // 水平方向速度分量
    double v_y = v * sin(angle_rad);            // 垂直方向速度分量

    // 計算到達網子 (2公尺處) 的時間與高度
    double t_net = 2.0 / v_x;                   // 水平距離2公尺時的時間
    double y_net = h + v_y * t_net - 0.5 * g * t_net * t_net; // 網子處的高度

    // 計算到達4公尺與6公尺的時間
    double t_4m = 4.0 / v_x;                   // 水平距離4公尺時的時間
    double t_6m = 6.0 / v_x;                   // 水平距離6公尺時的時間

    // 計算在4公尺與6公尺處的高度
    double y_4m = h + v_y * t_4m - 0.5 * g * t_4m * t_4m;
    double y_6m = h + v_y * t_6m - 0.5 * g * t_6m * t_6m;

    // 顯示每個計算過程
    cout << "角度: " << angle_deg << "°\n";
    cout << "  水平速度分量 (v_x): " << v_x << " m/s\n";
    cout << "  垂直速度分量 (v_y): " << v_y << " m/s\n";
    cout << "  到達網子 (2公尺處) 的時間 (t_net): " << t_net << " 秒\n";
    cout << "  網子處的高度 (y_net): " << y_net << " 公尺\n";

    // 判斷是否越過網子以及是否落在有效區域
    bool clears_net = y_net >= 1.55;           // 網子高度是否超過1.55公尺
    bool lands_in_valid_area = (y_4m > 0 && y_6m > 0); // 4米到6米處的羽毛球高度都要大於0

    // 顯示結果
    cout << "  是否越網: " << (clears_net ? "是" : "否") << "\n";               // 顯示是否越網
    cout << "  到達 4 米的時間 (t_4m): " << t_4m << " 秒\n";
    cout << "  4 米處的高度 (y_4m): " << y_4m << " 公尺\n";
    cout << "  到達 6 米的時間 (t_6m): " << t_6m << " 秒\n";
    cout << "  6 米處的高度 (y_6m): " << y_6m << " 公尺\n";
    cout << "  是否落在有效區: " << (lands_in_valid_area ? "是" : "否") << "\n"; // 顯示是否落在有效區
    cout << "--------------------------------\n";

    return { y_net, clears_net, lands_in_valid_area };
}

int main() {
    double angles[] = { 15, 30, 45 }; // 測試角度

    for (double angle : angles) {
        shuttlecock_trajectory(angle); // 計算並輸出每個角度的計算過程
    }

    return 0;
}
