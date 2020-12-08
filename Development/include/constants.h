#pragma once

#include "stdafx.h"

inline double& PI()
{
	static double pi = 3.14159265;
	return pi;
}