#include "GameWorld.h"

const float GameWorld::kPpm = 72.0f;

GameWorld::GameWorld(const b2Vec2& gravity) :
	_layer(ax::LayerColor::create(ax::Color4B::GRAY)),
	_world(std::make_unique<b2World>(gravity))
{
	// the hack to shift layer position
	/*_layer->setContentSize(ax::Vec2(ax::Director::getInstance()->getVisibleSize().width, ax::Director::getInstance()->getVisibleSize().height));
	_layer->setIgnoreAnchorPointForPosition(false);
	_layer->setAnchorPoint({ 0.5f, 0.5f });*/

	// static body
	createGroundBody();
}

void GameWorld::createGroundBody()
{
	b2BodyBuilder bodyBuilder(_world.get());

	b2Body* body = bodyBuilder.type(b2BodyType::b2_staticBody)
		.position(640, 360, kPpm)
		.buildBody();

	bodyBuilder.newRectangleFixture(5.0f, 5.0f, kPpm)
		.buildFixture();
}

GameWorld* GameWorld::getInstance()
{
	// gravity of -10
	static GameWorld instance({ 0, -10 });
	return &instance;
}

ax::LayerColor* GameWorld::getLayer() const
{
	return _layer;
}

b2World* GameWorld::getWorld() const
{
	return _world.get();
}