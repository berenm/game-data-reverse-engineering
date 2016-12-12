Beyond Good and Evil
--------------------------------------------------------------------------------

Quite obfuscated file format, with very few resources.

Game engine
================================================================================

Game engine is JADE Engine, custom made for Beyond Good and Evil and re-used on
the Prince of Persia trilogy, among other. Engine is not generic and is tailored
for each game. The data file probably as well.

Assets are stored in a single file named ``sally_clean.bf``.

BF file format
================================================================================

BF stands for Big File. It consists of a header followed by an ``id and offset``
table, a ``file`` table, a ``folder`` table, then the resource data.

Each resource has one entry in the ``id and offset`` table and one in the ``file``
table. The tables have a capacity and a size and may not be filled. 

Each file is linked to a ``folder``, which has one entry in the ``folder`` table.

Each folder is linked to is siblings, its parent, and the first file in the
folder.

The resource data is sometimes compressed with LZO1X algorithm, usually the
files located in the Bin folder, with ``.bin`` extension.
