#ifndef __HUD_H__
#define __HUD_H__

#include "axys.h"
#include "ui/UIImageView.h"

class Hud
{
public:
	static Hud* getInstance();
	virtual ~Hud() = default;

	ax::Layer* getLayer() const;
private:
	Hud();

	ax::Layer* _layer;

	ax::ui::ImageView* _logo;
};

#endif // !__HUD_H__
