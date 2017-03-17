//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Design a Snake game that is played on a device with screen size = width x height.
    Play the game online if you are not familiar with the game.

    The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

    You are given a list of food's positions in row-column order. When a snake eats the
    food, its length and the game's score both increase by 1.

    Each food appears one by one on the screen. For example, the second food will not
    appear until the first food was eaten by the snake.

    When a food does appear on the screen, it is guaranteed that it will not appear on
    a block occupied by the snake.

    Example:
    Given width = 3, height = 2, and food = [[1,2],[0,1]].

    Snake snake = new Snake(width, height, food);

    Initially the snake appears at position (0,0) and the food at (1,2).

    |S| | |
    | | |F|

    snake.move("R"); -> Returns 0

    | |S| |
    | | |F|

    snake.move("D"); -> Returns 0

    | | | |
    | |S|F|

    snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the
    'second food appears at (0,1) )

    | |F| |
    | |S|S|

    snake.move("U"); -> Returns 1

    | |F|S|
    | | |S|

    snake.move("L"); -> Returns 2 (Snake eats the second food)

    | |S|S|
    | | |S|

    snake.move("U"); -> Returns -1 (Game over because snake collides with border)
 */

#include "Design.h"

class SnakeGame {
    int w, h, food_idx;
    vector<pair<int, int>> food;
    // // There is no standard way of computing a hash on a pair.
    // static constexpr auto pair_hash = [](pair<int, int> const& a) {
    //     std::hash<int> int_hasher;
    //     return int_hasher(a.first) ^ int_hasher(a.second);
    // };
    // unordered_set<pair<int, int>, decltype(pair_hash)> body;
    unordered_set<int> body;
    deque<pair<int, int>> snake;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) : w(width), h(height), food(food) {
        food_idx = 0;
        body.insert(0);
        snake.push_back({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = snake.back().first, col = snake.back().second;

        auto tail = snake.front();
        snake.pop_front();
        body.erase(tail.first * w + tail.second);

        if (direction == "U") {
            --row;
        } else if (direction == "D") {
            ++row;
        } else if (direction == "L") {
            --col;
        } else if (direction == "R") {
            ++col;
        }
        if (row < 0 || row >= h || col < 0 || col >= w || body.find(row * w + col) != body.end()) return -1;
        snake.push_back({row, col});
        body.insert(row * w + col);

        if (food_idx >= food.size()) return snake.size() - 1;

        if (row == food[food_idx].first && col == food[food_idx].second) {
            ++food_idx;
            snake.push_front(tail);
            body.insert(tail.first * w + tail.second);
        }

        return snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */