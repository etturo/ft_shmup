#include "Terrain.hpp"

void Terrain::update(t_gamestate &state)
{
	this->delta_time += state.delta_time;

	if (SECONDS(this->delta_time) > 0.12f){
		rows.pop_back();
		rows.push_front(generate_row());
		this->delta_time = 0;
	}
}

void Terrain::render(WINDOW *win)
{
	wattron(win, COLOR_PAIR(1) | A_DIM);

	for (int i = 0; i < height; i++){
		mvwprintw(win, i, 0, "%s", rows[i].c_str());
	}

	wattroff(win, COLOR_PAIR(1) | A_DIM);
}

Terrain::Terrain(int width, int height)
{
	this->width = width;
	this->height = height;
	delta_time = 0;

	for (int i = 0; i < height; i++)
		rows.push_back(generate_row());
}

Terrain::~Terrain()
{
}
