#pragma once
#include "Object.h"

class Tank :public Object
{
public:
	enum Type
	{
		TURTLE,
		CLASSIC,
		DOUBLE
	};

public:
	Tank(Type type = CLASSIC, const Transform& transform = Transform());

	void Update(const Camera& camera) override;
	void Draw() const override;
	void UpdateThenDraw(const Camera& camera) override;

	// Actions
	void SetRotateTurret(bool rotateTurret);

private:
	class Base :public Object
	{
	public:
		Base(Type type, const Transform& transform);
		friend Tank;

		void Update(const Camera& camera) override;
	};

	class Turret :public Object
	{
	public:
		Turret(Type type, const Transform& transform);
		friend Tank;

		void Update(const Camera& camera) override;

	private:
		bool m_rotate;
	};

	class Tracks :public Object
	{
	public:
		Tracks(Type type, const Transform& transform);
		friend Tank;

		void Update(const Camera& camera) override;
	};

private:
	// File Paths
	static const std::string s_turtleFile;
	static const std::string s_classicFile;
	static const std::string s_doubleFile;

private:
	// Components
	Base m_base;
	Turret m_turret;
	Tracks m_tracks;

	// Logic
	Type m_type;

};
