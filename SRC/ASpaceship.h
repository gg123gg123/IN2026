#ifndef __ASPACESHIP_H__
#define __ASPACESHIP_H__

#include "GameUtil.h"
#include "GameObject.h"
#include "Shape.h"

class ASpaceship : public GameObject
{
public:
	ASpaceship();
	ASpaceship(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r);
	ASpaceship(const ASpaceship& s);
	virtual ~ASpaceship(void);

	virtual void Update(int t);
	virtual void Render(void);

	virtual void Thrust(float t);
	virtual void Rotate(float r);
	virtual void Shoot(void);

	void SetSpaceshipShape(shared_ptr<Shape> Aspaceship_shape) { mASpaceshipShape =Aspaceship_shape; }
	void SetThrusterShape(shared_ptr<Shape> Athruster_shape) { mAThrusterShape = Athruster_shape; }
	void SetBulletShape(shared_ptr<Shape> Abullet_shape) { mABulletShape = Abullet_shape; }

	bool ACollisionTest(shared_ptr<GameObject> o);
	void AOnCollision(const GameObjectList &objects);

private:
	float mThrust;

	shared_ptr<Shape> mASpaceshipShape;
	shared_ptr<Shape> mAThrusterShape;
	shared_ptr<Shape> mABulletShape;
};

#endif