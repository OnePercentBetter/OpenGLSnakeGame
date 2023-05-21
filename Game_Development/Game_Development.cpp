
#include "Game_Development.h"

SPRING_GAME_DEVELOPMENT_APP::SPRING_GAME_DEVELOPMENT_APP()
	: mHead("../Assets/Images/snake_segment.png", { 100,100 }),
	Final("../Assets/Images/game_over.png"),
	Ending(false),
	xRand(rand() % 750),
	yRand(rand() % 550),
	mFood("../Assets/Images/food.png", { xRand, yRand }),
	i(0),
	Score({
		"../Assets/Images/1.png",
		"../Assets/Images/2.png",
		"../Assets/Images/3.png",
		"../Assets/Images/4.png",
		"../Assets/Images/5.png",
		"../Assets/Images/6.png",
		"../Assets/Images/7.png",
		"../Assets/Images/8.png",
		"../Assets/Images/9.png",
		"../Assets/Images/10.png",
		"../Assets/Images/11.png",
		"../Assets/Images/12.png",
		"../Assets/Images/13.png",
		"../Assets/Images/14.png",
		"../Assets/Images/15.png",
		"../Assets/Images/16.png",
		"../Assets/Images/17.png",
		"../Assets/Images/18.png",
		"../Assets/Images/19.png",
		"../Assets/Images/20.png"
		})
{
	SetKeyPressedCallback([this](const FuelEngine::KeyPressed& e) { MyKeyPressedFunc(e); });
	FuelEngine::ScreenCoord c = mHead.GetCoords();
	element.push_back(FuelEngine::Unit{ "../Assets/Images/snake_segment.png", {c.xCoord, c.yCoord} });
}

void SPRING_GAME_DEVELOPMENT_APP::OnUpdate()
{
	FuelEngine::ScreenCoord test{ mHead.GetCoords() };
	if (Ending || test.xCoord < 0 || test.xCoord > 799 || test.yCoord < 0 || test.yCoord > 599)
	{
		renderer.Clear();
		renderer.Draw(Final, { 0, 100 });
		FuelEngine::FuelEngineApp::DefaultWindowCloseHandler();
	}
	else
	{
		renderer.Clear();
		renderer.Draw(mHead);
		renderer.Draw(mFood);
		if (element.size() <= 20 || (FuelEngine::UnitsOverlap(mFood, mHead) && element.size() <= 20))
		{
			FuelEngine::Image el(Score[element.size() - 1]);
			renderer.Draw(el, { 720, 720 });
		}
		for (auto& segment : element)
		{
			FuelEngine::ScreenCoord e = element.front().GetCoords();
			FuelEngine::ScreenCoord r = segment.GetCoords();
			if (r.xCoord == e.xCoord && r.yCoord == e.yCoord)
			{
				// Handle collision logic here
			}
			else
			{
				renderer.Draw(segment);
			}
		}
	}
}

void SPRING_GAME_DEVELOPMENT_APP::MyKeyPressedFunc(const FuelEngine::KeyPressed& e)
{
	// If Food and snakeHead Overlap
	if (FuelEngine::UnitsOverlap(mFood, mHead))
	{
		mFood.SetCoords({ rand() % 800, rand() % 600 });
		FuelEngine::ScreenCoord e = element.front().GetCoords();
		element.insert(element.begin(), FuelEngine::Unit{ "../Assets/Images/snake_segment.png", {e.xCoord - 50, e.yCoord} });
		for (auto& segment : element)
		{
			FuelEngine::ScreenCoord r = segment.GetCoords();
			if (r.xCoord == e.xCoord && r.yCoord == e.yCoord)
			{
				// Handle collision logic here
			}
			else
			{
				renderer.Draw(segment);
			}
		}
	}

	if (e.GetKeyCode() == FUELENGINE_KEY_RIGHT)
	{
		if (element.size() > 0)
		{
			FuelEngine::ScreenCoord m = mHead.GetCoords();
			if (element.size() >= 1 && (m.xCoord + 50) != element[element.size() - 1].GetCoords().xCoord)
			{
				mHead.UpdateXCoord(50);
				for (int i = element.size() - 1; i >= 0; i--)
				{
					FuelEngine::ScreenCoord n = element[i].GetCoords();
					element[i].UpdateXCoord(m.xCoord - n.xCoord);
					element[i].UpdateYCoord(m.yCoord - n.yCoord);
					m = n;
				}
			}
		}
	}
	else if (e.GetKeyCode() == FUELENGINE_KEY_LEFT)
	{
		if (element.size() > 0)
		{
			FuelEngine::ScreenCoord m = mHead.GetCoords();
			if (element.size() >= 1 && (m.xCoord - 50) != element[element.size() - 1].GetCoords().xCoord)
			{
				mHead.UpdateXCoord(-50);
				for (int i = element.size() - 1; i >= 0; i--)
				{
					FuelEngine::ScreenCoord n = element[i].GetCoords();
					element[i].UpdateXCoord(m.xCoord - n.xCoord);
					element[i].UpdateYCoord(m.yCoord - n.yCoord);
					m = n;
				}
			}
		}
	}
	else if (e.GetKeyCode() == FUELENGINE_KEY_UP)
	{
		if (element.size() > 0)
		{
			FuelEngine::ScreenCoord m = mHead.GetCoords();
			if (element.size() >= 1 && (m.yCoord + 50) != element[element.size() - 1].GetCoords().yCoord)
			{
				mHead.UpdateYCoord(50);
				for (int i = element.size() - 1; i >= 0; i--)
				{
					FuelEngine::ScreenCoord n = element[i].GetCoords();
					element[i].UpdateXCoord(m.xCoord - n.xCoord);
					element[i].UpdateYCoord(m.yCoord - n.yCoord);
					m = n;
				}
			}
		}
	}
	else if (e.GetKeyCode() == FUELENGINE_KEY_DOWN)
	{
		if (element.size() > 0)
		{
			FuelEngine::ScreenCoord m = mHead.GetCoords();
			if (element.size() >= 1 && (m.yCoord - 50) != element[element.size() - 1].GetCoords().yCoord)
			{
				mHead.UpdateYCoord(-50);
				for (int i = element.size() - 1; i >= 0; i--)
				{
					FuelEngine::ScreenCoord n = element[i].GetCoords();
					element[i].UpdateXCoord(m.xCoord - n.xCoord);
					element[i].UpdateYCoord(m.yCoord - n.yCoord);
					m = n;
				}
			}
		}
	}
}