class IUpdateable
{
private:
	bool enabled;
	int updateOrder;

public:
	virtual void Update() = 0;
	bool Enabled() { return enabled; }
	int UpdateOrder() { return updateOrder; }
};