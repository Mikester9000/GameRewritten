#pragma once
// tp_tracy.hpp — Tracy profiler integration helpers (MIT licence).
//
// GR_ENABLE_TRACY is defined automatically for Debug builds via the project
// preprocessor definitions in ThirdParty.vcxproj and GameRewritten.vcxproj.
// When NOT defined (Release builds), all macros below expand to nothing —
// zero runtime cost, zero binary size impact.
//
// Usage:
//   // At the end of each rendered frame:
//   GR_FRAME_MARK;
//
//   // Wrap a code block with a named zone:
//   { GR_ZONE_SCOPED_N("Physics Step"); tp::Physics::Step(dt); }
//
// Tracy profiler UI download: https://github.com/wolfpld/tracy/releases
// Connect the profiler to the running Debug build on localhost.

#ifdef GR_ENABLE_TRACY
  // Activate Tracy client when our debug flag is set.
#  ifndef TRACY_ENABLE
#    define TRACY_ENABLE
#  endif
#  include "../../third_party/tracy/tracy/Tracy.hpp"

#  define GR_FRAME_MARK         FrameMark
#  define GR_ZONE_SCOPED_N(nm)  ZoneScopedN(nm)
#else
  // Release (or any build without GR_ENABLE_TRACY): all macros are no-ops.
#  define GR_FRAME_MARK
#  define GR_ZONE_SCOPED_N(nm)
#endif
