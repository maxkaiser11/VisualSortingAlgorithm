#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>

void draw_state(std::vector<int> &v, SDL_Renderer *renderer, unsigned int red, unsigned int blue);

int main(int argc, char *argv[])
{
    std::random_device rd;
    std::uniform_int_distribution d(1, 99);
    std::vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(d(rd));
    }

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(100 * 10, 100 * 10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    // sort algo
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = i; j < v.size(); j++)
        {
            if (v[j] < v[i])
            {
                std::swap(v[j], v[i]);
            }
            // clear screen
            //
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Draw the state of the sort
            draw_state(v, renderer, i, j);

            // Show to window
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
    for (int i : v)
    {
        std::cout << i << " ";
    }
    if (std::ranges::is_sorted(v))
    {
        std::cout << "Sorted!\n";
    }
    return 0;
}

void draw_state(std::vector<int> &v, SDL_Renderer *renderer, unsigned int red, unsigned int blue)
{
    int index = 0;
    for (int i : v)
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1;
    }
}
