#include "Application.h"
#include "SoundManager.h"
#include "Title.h"
#include "Game.h"
#include "Loading.h"
#include "MoveCursor.h"

int main()
{
	// Requirement variables
	Application application = Application("Re Dot Empty Two", Version(1, 0, 0), 200, 50, 60);
	SoundManager soundManager = SoundManager();
	Title title = Title(&application);
	Game game = Game(&application);

	application.ShowInfo();
	soundManager.PlayBgm(true);
	title.Draw();

	// Select
	MoveCursor moveCursor = MoveCursor(2);

	unsigned short select = 0;

	moveCursor.SetPositionByIndex(0, Vector2((application.GetWidth() >> 1) - 10.0f, (application.GetHeight() >> 1) + 10.0f)).SetPositionByIndex(1, Vector2((application.GetWidth() >> 1) - 10.0f, (application.GetHeight() >> 1) + 14.0f)).ShowPosition(0);

	while (true)
	{
		short temp = moveCursor.Loop();

		if (temp == -5)
		{
			break;
		}
		else if (temp != -1)
		{
			select = temp;
		}
	}

	// Load
	Loading loading;

	switch (select)
	{
	case 0:
		loading = Loading();

		loading.LoadScene();
		game.Draw();

		break;
	case 1:
		return 0;
	}

	application.Run();

	return 0;
}