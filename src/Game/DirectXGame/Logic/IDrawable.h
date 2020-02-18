class IDrawable
{
private:
	bool visible;
	int drawOrder;
	
public:
	virtual void Draw() = 0;
	bool Visible() { return visible; }
	int DrawOrder() { return drawOrder; }
};