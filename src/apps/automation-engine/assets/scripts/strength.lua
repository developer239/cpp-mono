function onUpdate()
    ticks = sdl_get_ticks()

    entities = get_entities_by_group("Area")

    for i, entity in ipairs(entities) do
        print(i, entity.get_id)
    end
end

Level = {
    window = {
        windowX = 0,
        windowY = 60,
    },
    targets = {
        [0] = {
            tag = "Apple",
            detectColors = {
                lowerRed = 0,
                lowerGreen = 0,
                lowerBlue = 105,
                upperRed = 200,
                upperGreen = 65,
                upperBlue = 255,
                minWidth = 22,
                minHeight = 22
            },
            erodeDilate = {
                width = 10,
                height = 10,
            }
        },
        {
            tag = "Star",
            detectColors = {
                lowerRed = 0,
                lowerGreen = 135,
                lowerBlue = 105,
                upperRed = 75,
                upperGreen = 255,
                upperBlue = 255,
                minWidth = 15,
                minHeight = 15
            },
            erodeDilate = {
                width = 10,
                height = 10,
            }
        }
    },
    entities = {
        [0] = {
            tag = "AreaTop",
            group = "Area",
            components = {
                boundingBox = {
                    x = 140,
                    y = 230,
                    width = 160,
                    height = 105
                },
            }
        },
        {
            tag = "AreaMid",
            group = "Area",
            components = {
                boundingBox = {
                    x = 140,
                    y = 358,
                    width = 180,
                    height = 7
                },
            }
        },
        {
            tag = "AreaBottom",
            group = "Area",
            components = {
                boundingBox = {
                    x = 140,
                    y = 426,
                    width = 180,
                    height = 7
                },
            }
        },
        {
            tag = "AreaBack",
            group = "Area",
            components = {
                boundingBox = {
                    x = 37,
                    y = 324,
                    width = 28,
                    height = 64
                },
            }
        },
    }
}