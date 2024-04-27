//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Point {
//public:
//    int x, y;
//    Point() {
//    }
//
//    Point(int x_, int y_) {
//        x = x_;
//        y = y_;
//    }
//};
//
//class Field {
//public:
//    Field() {
//        whiteCount = 0;
//        blueCount = 0;
//    }
//
//    vector<vector<int> > v;
//    int whiteCount;
//    int blueCount;
//    int size;
//    Point start, end;
//};
//
//int whiteCount = 0;
//int blueCount = 0;
//void Fill(Field* parent, Field* field) {
//    int fieldIdxX, fieldIdxY;
//
//    field->v.resize(field->end.y - field->start.y);
//    for (int y = field->start.y; y < field->end.y; y++) {
//        fieldIdxY = y - field->start.y;
//        field->v[fieldIdxY].resize(field->end.x - field->start.x);
//
//        for (int x = field->start.x; x < field->end.x; x++) {
//            fieldIdxX = x - field->start.x;
//            field->v[fieldIdxY][fieldIdxX] = parent->v[y][x];
//
//            if (field->v[fieldIdxY][fieldIdxX] == 0) {
//                field->whiteCount++;
//            } else {
//                field->blueCount++;
//            }
//        }
//    }
//}
//
//void Divide(Field* field) {
//    if (field->size * field->size == field->whiteCount) {
//        whiteCount++;
//        return;
//    } else if (field->size * field->size == field->blueCount) {
//        blueCount++;
//        return;
//    }
//
//    int n = field->size / 2;
//
//    // 좌상단
//    Field* leftTop = new Field();
//    leftTop->size = n;
//    leftTop->start = Point(0, 0);
//    leftTop->end = Point(leftTop->start.x + n, leftTop->start.y + n);
//    Fill(field, leftTop);
//    Divide(leftTop);
//
//    // 우상단
//    Field* rightTop = new Field();
//    rightTop->size = n;
//    rightTop->start = Point(n, 0);
//    rightTop->end = Point(rightTop->start.x + n, rightTop->start.y + n);
//    Fill(field, rightTop);
//    Divide(rightTop);
//
//    // 좌하단
//    Field* leftBottom = new Field();
//    leftBottom->size = n;
//    leftBottom->start = Point(0, n);
//    leftBottom->end = Point(leftBottom->start.x + n, leftBottom->start.y + n);
//    Fill(field, leftBottom);
//    Divide(leftBottom);
//
//    // 우하단
//    Field* rightBottom = new Field();
//    rightBottom->size = n;
//    rightBottom->start = Point(n, n);
//    rightBottom->end = Point(rightBottom->start.x + n, rightBottom->start.y + n);
//    Fill(field, rightBottom);
//    Divide(rightBottom);
//}
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    Field* field = new Field();
//
//    int n, v;
//    cin >> n;
//
//    field->v.resize(n);
//    field->start = Point(0, 0);
//    field->end = Point(n, n);
//
//    for (int y = 0; y < n; y++) {
//        field->v[y].resize(n);
//
//        for (int x = 0; x < n; x++) {
//            cin >> v;
//
//            field->v[y][x] = v;
//
//            if (v == 0)
//                field->whiteCount++;
//            else
//                field->blueCount++;
//        }
//    }
//    field->size = n;
//
//    Divide(field);
//
//    cout << whiteCount << '\n' << blueCount;
//
//    return 0;
//}
