#include "../include/core/Utils.hpp"

long long int get_current_time() {
	return std::chrono::steady_clock::now().time_since_epoch().count();
}