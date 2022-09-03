#ifndef __HUD_H__
#define __HUD_H__

#include "axys.h"
#include "ui/UIImageView.h"

class Hud
{
public:
	static Hud* getInstance();
	virtual ~Hud() = default;

	ax::LayerColor* getLayer() const;
private:
	Hud();

	ax::LayerColor* _layer;

	ax::ui::ImageView* _logo;
};

#endif // !__HUD_H__
