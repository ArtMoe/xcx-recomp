// Loose RomFS mod files in place of sts.ard entries, switchable while the game runs (runtime/romfs_mods.c; the game
// side is recomp/romfs_mods.py).
#pragma once
#include <stddef.h>
#include <stdint.h>

// Called by the generated C where the archive device loads its list of declined paths (prefixes, NUL-terminated,
// ended by an empty string) for the path operation on path (a guest string): a list holding just that path when an
// enabled mod has a file for it, so the game opens rom:/<path> instead; else list unchanged.
uint64_t romfs_mod_declines(uint64_t list, uint64_t path);

// The host path of an enabled mod's file for a RomFS path ("rom:/chr/..." or "chr/..."), copied to out (may be NULL);
// 0 when none.
int romfs_mod_file(const char *path, char *out, size_t cap);
