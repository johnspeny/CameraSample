#include "HelloWorldScene.h"

USING_NS_AX;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	this->setContentSize(ax::Vec2(ax::Director::getInstance()->getVisibleSize().width, ax::Director::getInstance()->getVisibleSize().height));
	this->setIgnoreAnchorPointForPosition(false);
	this->setAnchorPoint({ 0.5f, 0.5f });

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto safeArea = Director::getInstance()->getSafeAreaRect();
	auto safeOrigin = safeArea.origin;

	// default othographic camera for game world
	// user1 camera for HUD
	const auto& winSize = Director::getInstance()->getWinSize();
	_gameCamera = getDefaultCamera();
	_gameCamera->initOrthographic(winSize.width, winSize.height, 1, 1000);
	_gameCamera->setPosition({ 0, 0 });

	//// Initialize HUD Camera
	_hudCamera = ax::Camera::createOrthographic(winSize.width, winSize.height, 1, 1000);
	_hudCamera->setDepth(2);
	_hudCamera->setCameraFlag(ax::CameraFlag::USER1);
	const ax::Vec3& eyePosOld = _gameCamera->getPosition3D();
	ax::Vec3 eyePos(eyePosOld);
	_hudCamera->setPosition3D(eyePosOld);
	_hudCamera->lookAt(eyePos);
	_hudCamera->setPosition(0, 0);
	addChild(_hudCamera);

	// Initialize Hud
	_hud = Hud::getInstance();
	_hud->getLayer()->setCameraMask(static_cast<uint16_t>(CameraFlag::USER1));
	addChild(_hud->getLayer());

	// Initialize Game World which has a static body at position 0,0
	_gameWorld = GameWorld::getInstance();
	addChild(_gameWorld->getLayer());

	// Create b2DebugRenderer
	_b2dr = b2DebugRenderer::create(_gameWorld->getWorld());
	_b2dr->setVisible(true);
	addChild(_b2dr);

	return true;
}