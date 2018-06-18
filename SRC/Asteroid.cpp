#include "Asteroid.h"
#include "Asteroids.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "GameUtil.h"
#include "GameWindow.h"
#include "GameWorld.h"
#include "GameDisplay.h"
#include "Spaceship.h"
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "GUILabel.h"
#include "Explosion.h"

Asteroid::Asteroid(void) : GameObject("Asteroid")
{
	mAngle = rand() % 360;
	mRotation = rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD*mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD*mAngle);
	mVelocity.z = 0.0;
}

Asteroid::~Asteroid(void)
{
}

bool Asteroid::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}



void Asteroid::OnCollision(const GameObjectList& objects)
{
	shared_ptr<GameObject> g = GetThisPtr();

	GLVector3f asteroidPos = g->GetPosition();

	mWorld->FlagForRemoval(GetThisPtr());

	if (g->GetScale() > 0.05f) {
		int num_asteroids = 3;
		for (uint i = 0; i < num_asteroids; i++)
		{
			Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("asteroid1");
			shared_ptr<Sprite> asteroid_sprite
				= make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
			asteroid_sprite->SetLoopAnimation(true);
			shared_ptr<GameObject> asteroid = make_shared<Asteroid>();
			asteroid->SetBoundingShape(make_shared<BoundingSphere>(asteroid->GetThisPtr(), 3.3f));
			asteroid->SetSprite(asteroid_sprite);
			asteroid->SetPosition(asteroidPos);
			asteroid->SetScale(g->GetScale()*0.33f);
			mWorld->AddObject(asteroid);

		}

		
		//code for the smaller collisons to be able to make the sprite smaller
		//if (g->GetScale() < 0.12f && g->GetScale() > 0.04f)
		//{
			//int num_asteroids = 2;
			//for (uint i = 0; i < num_asteroids; i++)
			//{
				//Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("asteroid1");
				//shared_ptr<Sprite> asteroid_sprite = make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
				//asteroid_sprite->SetLoopAnimation(true);
				//shared_ptr<GameObject> asteroid = make_shared<Asteroid>();
				//asteroid->SetBoundingShape(make_shared<BoundingSphere>(asteroid->GetThisPtr(), 3.3f));
				//asteroid->SetSprite(asteroid_sprite);
				//asteroid->SetPosition(asteroidPos);
				//asteroid->SetScale(g->GetScale()*0.66f);
				//mWorld->AddObject(asteroid);

			//}


		}

	}


