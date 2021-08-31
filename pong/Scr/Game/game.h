#ifndef Game_H
#define Game_H

namespace game {

	enum GameScreen
	{
		Menu = 0,
		Game,
		End,
		Credits,
		Controls
	};
	extern GameScreen Screens;

	int core();

}

#endif // Game_H