#ifndef TERRAIN_HPP
# define TERRAIN_HPP

#include "settings.hpp"
#include "Updatable.hpp"

class Terrain : public Updatable
{
private:
	std::deque<std::string> rows;
	long long delta_time;
	int width, height;

	std::string generate_row(){
		std::string row = "";
		std::string new_piece = "";
		for (int i = 0; i < width; i += new_piece.length()){
			int chance = rand() % 150;
			new_piece = " ";
			if (chance < 2){
				new_piece = "*";
				row += new_piece;
			}
			else if (chance < 5){
				row += "-";
			}
			else if (chance < 8){
				row += ".";
			}
			else
				row += " ";
		}
		return row;
	}
public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win);

	Terrain(int width, int height);
	~Terrain();
};

#endif