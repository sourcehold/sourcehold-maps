import { Section, CompressedSection, DataSection, SizePrefixedSection } from './abstract/Sections'

export class MapPropertySection1 extends SizePrefixedSection {

}

export class MapPropertySection2 extends SizePrefixedSection {

}

export class MapPropertySection3 extends SizePrefixedSection {

}

export class MapPropertySection4 extends SizePrefixedSection {

}

export class Section1001 extends CompressedSection {

}

export const MAP_SECTIONS: Record<string, typeof Section> = {
  1001: Section1001
}

export function getSectionClassForIndex (index: string | number, compressed: boolean) {
  if (Object.keys(MAP_SECTIONS).includes(index.toString())) {
    return MAP_SECTIONS[index]
  }
  if (compressed) {
    return CompressedSection
  }
  return DataSection
}
