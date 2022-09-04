#ifndef __GAMEWORLD_H__
#define __GAMEWORLD_H__

#include "axys.h"
#include "box2d/box2d.h"
#include "util/box2d/b2BodyBuilder.h"

class GameWorld
{
public:
	static GameWorld* getInstance();
	virtual ~GameWorld() = default;

	ax::LayerColor* getLayer() const;

	b2World* getWorld() const;
private:
	explicit GameWorld(const b2Vec2& gravity);
	ax::LayerColor* _layer;
	std::unique_ptr<b2World> _world;

	// pixel per meter
	static const float kPpm;

	void createGroundBody();
};

#endif // !__GAMEWORLD_H__
