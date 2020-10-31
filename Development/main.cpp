#include "stdafx.h"
#include "BookKeeping.h"

void main()
{
	Rep_Tags rep_tag;
	rep_tag.add("1tag");
	rep_tag.add("2tag");
	rep_tag.add("0tag");
	rep_tag.add("0tag");
	rep_tag.print();
	std::cout << "\n\n";
	rep_tag.add("3tag");
	rep_tag.add("111tag");
	rep_tag.print();
	std::cout << "\n\n";
	rep_tag.remove("111tag");
	rep_tag.print();
}