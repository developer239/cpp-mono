ACTIONS = {
    { areaType = "AreaTop", lastAt = 0 },
    { areaType = "AreaMid", lastAt = 0 },
    { areaType = "AreaBottom", lastAt = 0 },
    { areaType = "AreaBack", lastAt = 0 },
}

MIN_DELAY = 280;

function onUpdate()
    ticks = sdl_get_ticks()

    stars = get_entities_by_group("Star")
    areaBack = get_entity_by_tag("AreaBack")

    starIndexToPosition = {}

    for i, star in ipairs(stars) do
        starIndexToPosition[i] = {
            index = i,
            positionX = get_entity_bounding_box(star).positionX
        }
    end

    for i, starPosition in ipairs(starIndexToPosition) do
        print(i, starPosition.index)

        star = stars[starPosition.index]
        starBoundingBox = get_entity_bounding_box(star)
        areaBoundingBox = get_entity_bounding_box(areaBack)

        collisionHappened = check_aabb_collision(
                starBoundingBox.positionX,
                starBoundingBox.positionY,
                starBoundingBox.width,
                starBoundingBox.height,
                areaBoundingBox.positionX,
                areaBoundingBox.positionY,
                areaBoundingBox.width,
                areaBoundingBox.height
        )

        if collisionHappened and (ticks - ACTIONS[4].lastAt > MIN_DELAY) then
            if ticks - ACTIONS[4].lastAt > 100000 then
                print("Fixing position")
                ACTIONS[4].lastAt = sdl_get_ticks();
            else
                print("Press arrow left")
            end
        end

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