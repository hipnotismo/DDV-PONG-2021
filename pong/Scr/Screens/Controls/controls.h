#ifndef Controls_H
#define Controls_H

namespace controls {

	extern Color player1Color;
	extern Color player2Color;

	extern char upPlayer1;
	extern char downPlayer1;
	extern char upPlayer2;
	extern char downPlayer2;

	void initControls();
	void updateFrameControls();
}

#endif // Controls_H