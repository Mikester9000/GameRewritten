# Do Not Build Yet (Unless Explicitly Requested)

## Premature systems to avoid
- Overengineered rendering pipelines.
- Large quest frameworks.
- Advanced generic AI frameworks.
- Huge data-driven abstraction layers.
- Network/multiplayer systems.
- Full cinematic frameworks.
- Massive progression trees before baseline progression clarity.

## Why
- Increases drift, complexity, and maintenance burden.
- Slows core loop progress.
- Raises low-spec performance risk.

## Allowed exception
Build only when a task explicitly asks for it and scope is clear/safe.

## Preferred alternative
- Add small stubs/hooks with clear ownership.
- Keep behavior practical and testable now.
