#include "GameUtil.h"
#include "GameWorld.h"
#include "Bullet.h"
#include "ASpaceship.h"
#include "BoundingSphere.h"

using namespace std;

// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/**  Default constructor. */
ASpaceship::ASpaceship()
	: GameObject("ASpaceship"), mThrust(0)
{
}

/** Construct a spaceship with given position, velocity, acceleration, angle, and rotation. */
ASpaceship::ASpaceship(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r)
	: GameObject("ASpaceship", p, v, a, h, r), mThrust(0)
{
}

/** Copy constructor. */
ASpaceship::ASpaceship(const ASpaceship& s)
	: GameObject(s), mThrust(0)
{
}

/** Destructor. */
ASpaceship::~ASpaceship(void)
{
}

/** Update this spaceship. */
void ASpaceship::Update(int t)
{
	// Call parent update function
	GameObject::Update(t);
}

/** Render this spaceship. */
void ASpaceship::Render(void)
{
	if (mASpaceshipShape.get() != NULL) mASpaceshipShape->Render();

	// If ship is thrusting
	if ((mThrust > 0) && (mAThrusterShape.get() != NULL)) {
		mAThrusterShape->Render();
	}

	GameObject::Render();
}

/** Fire the rockets. */
void ASpaceship::Thrust(float t)
{
	mThrust = t;
	// Increase acceleration in the direction of ship
	mAcceleration.x = mThrust*cos(DEG2RAD*mAngle);
	mAcceleration.y = mThrust*sin(DEG2RAD*mAngle);
}

/** Set the rotation. */
void ASpaceship::Rotate(float r)
{
	mRotation = r;
}

/** Shoot a bullet. */
void ASpaceship::Shoot(void)
{
	// Check the world exists
	if (!mWorld) return;
	// Construct a unit length vector in the direction the spaceship is headed
	GLVector3f spaceship_heading(cos(DEG2RAD*mAngle), sin(DEG2RAD*mAngle), 0);
	spaceship_heading.normalize();
	// Calculate the point at the node of the spaceship from position and heading
	GLVector3f bullet1_position = mPosition + (spaceship_heading * 4);
	// Calculate how fast the bullet should travel
	float bullet1_speed = 20;
	// Construct a vector for the bullet's velocity
	GLVector3f bullet1_velocity = mVelocity + spaceship_heading * bullet1_speed;
	// Construct a new bullet
	shared_ptr<GameObject> bullet1
	(new Bullet(bullet1_position, bullet1_velocity, mAcceleration, mAngle, 0, 2000));
	bullet1->SetBoundingShape(make_shared<BoundingSphere>(bullet1->GetThisPtr(), 3.0f));
	bullet1->SetShape(mABulletShape);
	// Add the new bullet to the game world
	mWorld->AddObject(bullet1);

}

bool ASpaceship::ACollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Asteroid")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void ASpaceship::AOnCollision(const GameObjectList &objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}