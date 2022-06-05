function playStar()
    ticks = sdl_get_ticks()

    stars = get_entities_by_group("Star")
    areaBack = get_entity_by_tag("AreaBack")

    appleIndexToPosition = {}

    for i, star in ipairs(stars) do
        appleIndexToPosition[i] = {
            index = i,
            positionX = get_entity_bounding_box(star).positionX
        }
    end

    for i, starPosition in ipairs(appleIndexToPosition) do
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

        if collisionHappened and (ticks - Level["actions"][4].lastAt > Level["minDelay"]) then
            if ticks - Level["actions"][4].lastAt > 100000 then
                logError("Fixing timestamp")
                Level["actions"][4].lastAt = sdl_get_ticks();
            else
                log("Press arrow left")
                Level["actions"][4].lastAt = sdl_get_ticks();
                press_arrow_left();
            end
        end
    end
end

function playApple()
    ticks = sdl_get_ticks()

    areas = get_entities_by_group("Area")
    apples = get_entities_by_group("Apple")

    appleIndexToPosition = {}

    for i, apple in ipairs(apples) do
        appleIndexToPosition[i] = {
            index = i,
            positionX = get_entity_bounding_box(apple).positionX
        }
    end

    for i, applePosition in ipairs(appleIndexToPosition) do
        apple = apples[applePosition.index]
        appleBoundingBox = get_entity_bounding_box(apple)

        for j, area in ipairs(areas) do
            actionIndex = -1
            areaBoundingBox = get_entity_bounding_box(area)

            collisionHappened = check_aabb_collision(
                    appleBoundingBox.positionX,
                    appleBoundingBox.positionY,
                    appleBoundingBox.width,
                    appleBoundingBox.height,
                    areaBoundingBox.positionX,
                    areaBoundingBox.positionY,
                    areaBoundingBox.width,
                    areaBoundingBox.height
            )

            if (entity_has_tag(area, "AreaTop")) then
                actionIndex = 1
            end
            if (entity_has_tag(area, "AreaMid")) then
                actionIndex = 2
            end
            if (entity_has_tag(area, "AreaBottom")) then
                actionIndex = 3
            end

            if actionIndex > 0 then
                if collisionHappened and (ticks - Level["actions"][actionIndex].lastAt > Level["minDelay"]) then
                    if ticks - Level["actions"][actionIndex].lastAt > 100000 then
                        logError("Fixing timestamp")
                        Level["actions"][actionIndex].lastAt = sdl_get_ticks();
                    else
                        if (entity_has_tag(area, "AreaTop")) then
                            log("Press arrow up")
                            press_arrow_up()
                        end
                        if (entity_has_tag(area, "AreaMid")) then
                            log("Press arrow right")
                            press_arrow_right()
                        end
                        if (entity_has_tag(area, "AreaBottom")) then
                            log("Press arrow down")
                            press_arrow_down()
                        end

                        Level["actions"][actionIndex].lastAt = sdl_get_ticks();
                    end
                end
            end
        end
    end
end

function onUpdate()
    playApple()
    playStar()
end

Level = {
    actions = {
        { areaType = "AreaTop", lastAt = 0 },
        { areaType = "AreaMid", lastAt = 0 },
        { areaType = "AreaBottom", lastAt = 0 },
        { areaType = "AreaBack", lastAt = 0 },
    },
    minDelay = 280,
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