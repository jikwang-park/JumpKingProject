#pragma once

enum class Languages
{
	Korean,
	English,
	Japanese,
	Count,
};

enum class SortingLayers
{
	HitBox,
	Background,
	Midground,
	Foreground,
	Player,
	Default,
	UI,
};

enum class SceneIds
{
	None = -1,
	Dev1,
	Dev2,
	Count,
};

enum class Origins
{
	// T M B
	// L C R
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,
};

enum class Sides
{
	Left,
	Right,
	None,
};