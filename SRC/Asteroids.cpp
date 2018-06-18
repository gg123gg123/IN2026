#include "Asteroid.h"
#include "Asteroids.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "GameUtil.h"
#include "GameWindow.h"
#include "GameWorld.h"
#include "GameDisplay.h"
#include "ASpaceship.h"
#include "Spaceship.h"
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "GUILabel.h"
#include "IPlayerListener.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Explosion.h"
#include <string>

// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/** Constructor. Takes arguments from command line, just in case. */
Asteroids::Asteroids(int argc, char *argv[])
	: GameSession(argc, argv)
{
	mLevel = 0;
	mAsteroidCount = 0;
}

/** Destructor. */
Asteroids::~Asteroids(void)
{
}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

/** Start an asteroids game. */
void Asteroids::Start()
{
	// Create a shared pointer for the Asteroids game object - DO NOT REMOVE
	shared_ptr<Asteroids> thisPtr = shared_ptr<Asteroids>(this);

	// Add this class as a listener of the game world
	mGameWorld->AddListener(thisPtr.get());

	// Add this as a listener to the world and the keyboard
	mGameWindow->AddKeyboardListener(thisPtr);

	// Add a score keeper to the game world
	mGameWorld->AddListener(&mScoreKeeper);

	// Add this class as a listener of the score keeper
	mScoreKeeper.AddListener(thisPtr);

	// Create an ambient light to show sprite textures
	GLfloat ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
	glEnable(GL_LIGHT0);

	Animation *explosion_anim = AnimationManager::GetInstance().CreateAnimationFromFile("explosion", 64, 1024, 64, 64, "explosion_fs.png");
	Animation *asteroid1_anim = AnimationManager::GetInstance().CreateAnimationFromFile("asteroid1", 128, 8192, 128, 128, "asteroid1_fs.png");
	Animation *spaceship_anim = AnimationManager::GetInstance().CreateAnimationFromFile("spaceship", 128, 128, 128, 128, "spaceship_fs.png");


	// Create a spaceship and add it to the world
	mGameWorld->AddObject(CreateSpaceship());
	mGameWorld->AddObject(CreateAlienSpaceship());
	// Create some asteroids and add them to the world
	CreateAsteroids(2);

	//Create the GUI
	CreateGUI();

	// Add a player (watcher) to the game world
	mGameWorld->AddListener(&mPlayer);

	// Add this class as a listener of the player
	mPlayer.AddListener(thisPtr);

	// Start the game
	GameSession::Start();
}

/** Stop the current game. */
void Asteroids::Stop()
{
	// Stop the game
	GameSession::Stop();
}

// PUBLIC INSTANCE METHODS IMPLEMENTING IKeyboardListener /////////////////////
//if game over label is 
void Asteroids::OnKeyPressed(uchar key, int x, int y)
{
	 
	switch (key)
	{
	case ' ':
		mSpaceship->Shoot();
		break;
	default:
		break;
	case 'm':
		playername.push_back('m');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'a':
		playername.push_back('a');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'b':
		playername.push_back('b');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'c':
		playername.push_back('c');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'd':
		playername.push_back('d');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'e':
		playername.push_back('e');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'f':
		playername.push_back('f');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'g':
		playername.push_back('g');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'h':
		playername.push_back('h');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'i':
		playername.push_back('i');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'k':
		playername.push_back('k');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'l':
		playername.push_back('l');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'n':
		playername.push_back('n');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'o':
		playername.push_back('o');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'p':
		playername.push_back('p');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'q':
		playername.push_back('q');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'r':
		playername.push_back('r');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 's':
		playername.push_back('s');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 't':
		playername.push_back('t');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'u':
		playername.push_back('u');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'v':
		playername.push_back('v');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'w':
		playername.push_back('w');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'x':
		playername.push_back('x');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'y':
		playername.push_back('y');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case 'z':
		playername.push_back('z');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;
	case'/0':
		playername.push_back('/0');
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetVisible(false);
	

		break;
	case 8:
		playername.pop_back();
		contents = std::string(playername.begin(), playername.end());
		mPlayerNameLabel->SetText(contents);
		break;

	case 13:
		playername.push_back(13);
		contents = std::string(playername.begin(), playername.end());
	mPlayerNameLabel->SetVisible(false);
		

	//case '/b':
	//	playername.pop_back('');
		//contents = std::string(playername.begin(), playername.end());
		//mPlayerNameLabel->SetText(contents);
		//break;
		
	}
}

void Asteroids::OnKeyReleased(uchar key, int x, int y) {}

void Asteroids::OnSpecialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
		// If up arrow key is pressed start applying forward thrust
	case GLUT_KEY_UP: mSpaceship->Thrust(10); break;
		// If left arrow key is pressed start rotating anti-clockwise
	case GLUT_KEY_LEFT: mSpaceship->Rotate(90); break;
		// If right arrow key is pressed start rotating clockwise
	case GLUT_KEY_RIGHT: mSpaceship->Rotate(-90); break;
		case GLUT_KEY_INSERT: 
		break;
		// Default case - do nothing
	default: break;
	}
}

void Asteroids::OnSpecialKeyReleased(int key, int x, int y)
{
	switch (key)
	{
		// If up arrow key is released stop applying forward thrust
	case GLUT_KEY_UP: mSpaceship->Thrust(0); break;
		// If left arrow key is released stop rotating
	case GLUT_KEY_LEFT: mSpaceship->Rotate(0); break;
		// If right arrow key is released stop rotating
	case GLUT_KEY_RIGHT: mSpaceship->Rotate(0); break;
		// Default case - do nothing
	default: break;
	}
}


// PUBLIC INSTANCE METHODS IMPLEMENTING IGameWorldListener ////////////////////

void Asteroids::OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object)
{
	if (object->GetType() == GameObjectType("Asteroid"))
	{
		shared_ptr<GameObject> explosion = CreateExplosion();
		explosion->SetPosition(object->GetPosition());
		explosion->SetRotation(object->GetRotation());
		mGameWorld->AddObject(explosion);
		mAsteroidCount--;
		if (mAsteroidCount <= 0)
		
			SetTimer(500, START_NEXT_LEVEL);
		}
	}


// PUBLIC INSTANCE METHODS IMPLEMENTING ITimerListener ////////////////////////

void Asteroids::OnTimer(int value)
{
	if (value == CREATE_NEW_PLAYER)
	{
		mSpaceship->Reset();
		mGameWorld->AddObject(mSpaceship);
		mGameWorld->AddObject(mAlienSpaceship);
	}

	if (value == START_NEXT_LEVEL)
	{
		mLevel++;
		int num_asteroids = 3 + 2 * mLevel;
		CreateAsteroids(num_asteroids);
		
	}

	if (value == SHOW_GAME_OVER)
	{
		mGameOverLabel->SetVisible(true);
	//	string = name;
		//cout << "Please enter your name." << endl;
		//cin >> name >> ;
		//cout << "name:" << name << "score:" << s;
		
		file.open("Scores.txt", ios::app);
		file << s << "\n";
		file.close();
		fileT.open("test.txt", ios::app);
		fileT << s << "\n";
        fileT.close();
		//filen.open("new.txt", ios::app);
		//filen << s << " " << contents << "\n";
		//filen.close();
	}



}


// PROTECTED INSTANCE METHODS /////////////////////////////////////////////////
shared_ptr<GameObject> Asteroids::CreateSpaceship()
{
	// Create a raw pointer to a spaceship that can be converted to
	// shared_ptrs of different types because GameWorld implements IRefCount
	mSpaceship = make_shared<Spaceship>();
	mSpaceship->SetBoundingShape(make_shared<BoundingSphere>(mSpaceship->GetThisPtr(), 4.0f));
	shared_ptr<Shape> bullet_shape = make_shared<Shape>("bullet.shape");
	mSpaceship->SetBulletShape(bullet_shape);
	Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("spaceship");
	shared_ptr<Sprite> spaceship_sprite =
		make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
	mSpaceship->SetSprite(spaceship_sprite);
	mSpaceship->SetScale(0.1f);
	// Reset spaceship back to centre of the world
	mSpaceship->Reset();
	// Return the spaceship so it can be added to the world
	return mSpaceship;

}

shared_ptr<GameObject> Asteroids::CreateAlienSpaceship()
{
	// Create a raw pointer to a spaceship that can be converted to
	// shared_ptrs of different types because GameWorld implements IRefCount
	mAlienSpaceship = make_shared<Spaceship>();
	mAlienSpaceship->SetBoundingShape(make_shared<BoundingSphere>(mAlienSpaceship->GetThisPtr(), 4.0f));
shared_ptr<Shape> bullet_shape1 = make_shared<Shape>("bullet.shape");
	mAlienSpaceship->SetBulletShape(bullet_shape1);
	Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("spaceship");
	shared_ptr<Sprite> spaceship_sprite1 =
		make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
	mAlienSpaceship->SetSprite(spaceship_sprite1);
	mAlienSpaceship->SetScale(0.1f);
	// set alienship position
	mAlienSpaceship->SetPosition(15);
	mAlienSpaceship->SetRotation(-10);
	mAlienSpaceship->Thrust(0.1);
	// Return the spaceship so it can be added to the world
	return mAlienSpaceship;

}
void Asteroids::CreateAsteroids(const uint num_asteroids)
{
	mAsteroidCount = num_asteroids;
	for (uint i = 0; i < num_asteroids; i++)
	{
		Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("asteroid1");
		shared_ptr<Sprite> asteroid_sprite
			= make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
		asteroid_sprite->SetLoopAnimation(true);
		shared_ptr<GameObject> asteroid = make_shared<Asteroid>();
		asteroid->SetBoundingShape(make_shared<BoundingSphere>(asteroid->GetThisPtr(), 10.0f));
		asteroid->SetSprite(asteroid_sprite);
		asteroid->SetScale(0.2f);
		mGameWorld->AddObject(asteroid);
	}
}

void Asteroids::CreateGUI()
{
	//Search for the highscore
	//fileT.open("test.txt");
	//while (fileT >> ScoreSearch) {
		//if (hs < ScoreSearch) {
			//hs = ScoreSearch;
		//}
		file.open("scores.txt");
		while (file >> ScoreSearch) {
			if (hs < ScoreSearch) {
				hs = ScoreSearch;

			}

		}

		// Add a (transparent) border around the edge of the game display
		mGameDisplay->GetContainer()->SetBorder(GLVector2i(20, 20));
		// Create a new GUILabel and wrap it up in a shared_ptr
		mScoreLabel = make_shared<GUILabel>("Score: 0");

		// Set the vertical alignment of the label to GUI_VALIGN_TOP
		mScoreLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_TOP);

		// Add the GUILabel to the GUIComponent  
		shared_ptr<GUIComponent> score_component = static_pointer_cast<GUIComponent>(mScoreLabel);
		mGameDisplay->GetContainer()->AddComponent(score_component, GLVector2f(0.0f, 1.0f));


		// Create a new GUILabel and wrap it up in a shared_ptr
		mLivesLabel = make_shared<GUILabel>("Lives: 3");
		// Set the vertical alignment of the label to GUI_VALIGN_BOTTOM
		mLivesLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
		// Add the GUILabel to the GUIComponent  
		shared_ptr<GUIComponent> lives_component = static_pointer_cast<GUIComponent>(mLivesLabel);
		mGameDisplay->GetContainer()->AddComponent(lives_component, GLVector2f(0.0f, 0.0f));

		//highscore
		// Create a new GUILabel and wrap it up in a shared_ptr
		mHighScoreLabel = make_shared<GUILabel>("Highscore:");
		// Set the vertical alignment of the label to GUI_VALIGN_TOP
		mHighScoreLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
		//mHighScoreLabel->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
		// Add the GUILabel to the GUIComponent  
		shared_ptr<GUIComponent> highscore_component = static_pointer_cast<GUIComponent>(mHighScoreLabel);
		mGameDisplay->GetContainer()->AddComponent(highscore_component, GLVector2f(0.0f, 1.0f));


		// Create a new GUILabel and wrap it up in a shared_ptr
		mPlayerNameLabel = shared_ptr<GUILabel>(new GUILabel("Name:"));
		// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
		mPlayerNameLabel->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
		// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
		mPlayerNameLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_MIDDLE);
		// Set the visibility of the label to false (hidden)
		mPlayerNameLabel->SetVisible(true);
		// Add the GUILabel to the GUIContainer  
		shared_ptr<GUIComponent> name_component
			= static_pointer_cast<GUIComponent>(mPlayerNameLabel);
		mGameDisplay->GetContainer()->AddComponent(name_component, GLVector2f(0.5f, 0.5f));


		// Create a new GUILabel and wrap it up in a shared_ptr
		mGameOverLabel = shared_ptr<GUILabel>(new GUILabel("GAME OVER"));
		// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
		mGameOverLabel->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
		// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
		mGameOverLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_MIDDLE);
		// Set the visibility of the label to false (hidden)
		mGameOverLabel->SetVisible(false);
		// Add the GUILabel to the GUIContainer  
		shared_ptr<GUIComponent> game_over_component
			= static_pointer_cast<GUIComponent>(mGameOverLabel);
		mGameDisplay->GetContainer()->AddComponent(game_over_component, GLVector2f(0.5f, 0.5f));


		//fileT.open("test.txt");
		//std::ostringstream msg_stream;
		//msg_stream << "HighSore: " << hs <<" " << contents;
		//std::string highscore_msg = msg_stream.str();
		//mHighScoreLabel->SetText(highscore_msg);
		//fileT.close();

		//
		file.open("Scores.txt");
		std::ostringstream msg_stream;
		msg_stream << "HighSore: " << hs;
		std::string highscore_msg = msg_stream.str();
		mHighScoreLabel->SetText(highscore_msg);
		file.close();
	}


void Asteroids::OnScoreChanged(int score)
// Format the score message using an string-based stream
{
	std::ostringstream msg_stream;
	msg_stream << "Score: " << score;
	// Get the score message as a string
	std::string score_msg = msg_stream.str();
	mScoreLabel->SetText(score_msg);
	s = score;
	mAlienSpaceship->Shoot();
	

}




void Asteroids::OnPlayerKilled(int lives_left)
{
	shared_ptr<GameObject> explosion = CreateExplosion();
	explosion->SetPosition(mSpaceship->GetPosition());
	explosion->SetRotation(mSpaceship->GetRotation());
	mGameWorld->AddObject(explosion);

	// Format the lives left message using an string-based stream
	std::ostringstream msg_stream;
	msg_stream << "Lives: " << lives_left;
	// Get the lives left message as a string
	std::string lives_msg = msg_stream.str();
	mLivesLabel->SetText(lives_msg);

	if (lives_left > 0)
	{
		SetTimer(1000, CREATE_NEW_PLAYER);
	}
	else
	{
		SetTimer(500, SHOW_GAME_OVER);

	}

}

shared_ptr<GameObject> Asteroids::CreateExplosion()
{
	Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("explosion");
	shared_ptr<Sprite> explosion_sprite =
		make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
	explosion_sprite->SetLoopAnimation(false);
	shared_ptr<GameObject> explosion = make_shared<Explosion>();
	explosion->SetSprite(explosion_sprite);
	explosion->Reset();
	return explosion;
}

