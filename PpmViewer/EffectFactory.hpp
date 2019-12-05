#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreenEffect.hpp"
#include "RemoveBlueEffect.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GrayscaleEffect.hpp"
#include "RandomNoiseEffect.hpp"
#include "HighContrastEffect.hpp"
#include "FlipHorizontallyEffect.hpp"
#include "FlipVerticallyEffect.hpp"
#include "BlurEffect.hpp"
#include "PixelateEffect.hpp"
#include "Rotate90Effect.hpp"

// FLIP HORIZONTALLY, PIXELATE NEEDS FIX, ROTATE90 NEEDS TO BE DONE

enum class ImageEffectType
{
	RemoveRed,
	RemoveGreen,
	RemoveBlue,
	NegateRed,
	NegateGreen,
	NegateBlue,
	Grayscale,
	RandomNoise,
	HighContrast,
	FlipHorizontally,
	FlipVertically,
	Blur,
	Pixelate,
	Rotate90
};

class EffectFactory
{
public:
	static ImageEffect* createEffect(ImageEffectType effect_type)
	{
		switch (effect_type)
		{
		case ImageEffectType::RemoveRed:
			return new RemoveRedEffect{};
			break;
		case ImageEffectType::RemoveGreen:
			return new RemoveGreenEffect{};
			break;
		case ImageEffectType::RemoveBlue:
			return new RemoveBlueEffect{};
			break;
		case ImageEffectType::NegateRed:
			return new NegateRedEffect{};
			break;
		case ImageEffectType::NegateGreen:
			return new NegateGreenEffect{};
			break;
		case ImageEffectType::NegateBlue:
			return new NegateBlueEffect{};
			break;
		case ImageEffectType::Grayscale:
			return new GrayscaleEffect{};
			break;
		case ImageEffectType::RandomNoise:
			return new RandomNoiseEffect{};
			break;
		case ImageEffectType::HighContrast:
			return new HighContrastEffect{};
			break;
		case ImageEffectType::FlipHorizontally:
			return new FlipHorizontallyEffect{};
			break;
		case ImageEffectType::FlipVertically:
			return new FlipVerticallyEffect{};
			break;
		case ImageEffectType::Blur:
			return new BlurEffect{};
			break;
		case ImageEffectType::Pixelate:
			return new PixelateEffect{};
			break;
		case ImageEffectType::Rotate90:
			return new Rotate90Effect{};
			break;
		default: 
			break;
		}
	}
};